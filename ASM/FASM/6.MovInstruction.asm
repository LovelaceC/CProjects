Name : mov_instruction

.model small
.data

    variable db 12

.code

main proc        
    
    mov al, variable
    mov dh, al

    main endp

end
