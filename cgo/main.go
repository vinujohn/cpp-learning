package main

// #cgo CFLAGS: -g -Wall
// #include <stdlib.h>
// #include "greeter.h"
// #include <pthread.h>
import "C"
import (
	"bytes"
	"fmt"
	"runtime"
	"strconv"
	"sync"
	"unsafe"
)

var wg sync.WaitGroup

func main() {

	for i := 0; i < 100; i++ {
		wg.Add(1)
		go callC(i)
	}

	wg.Wait()
}

func callC(i int) {
	name := C.CString("Gopher")
	defer C.free(unsafe.Pointer(name))

	year := C.int(getGID())

	ptr := C.malloc(C.sizeof_char * 1024)
	defer C.free(unsafe.Pointer(ptr))

	g := C.struct_Greetee{
		name: name,
		year: year,
	}

	size := C.greet(&g, (*C.char)(ptr))

	b := C.GoBytes(ptr, size)
	fmt.Println(string(b))

	wg.Done()
}

func getGID() uint64 {
	b := make([]byte, 64)
	b = b[:runtime.Stack(b, false)]
	b = bytes.TrimPrefix(b, []byte("goroutine "))
	b = b[:bytes.IndexByte(b, ' ')]
	n, _ := strconv.ParseUint(string(b), 10, 64)
	return n
}
