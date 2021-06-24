Name : sizes

.model small
.data

    var1 db 12            ; One byte
    var2 dw 151           ; Two bytes
    var3 dd 115           ; Four bytes
    var4 dq 123456789     ; Eight bytes
    var5 dt 123456789000  ; Ten bytes

.code

main proc

    main endp

end
