G90 G0 X0 Y0 Z0 (Must have this on start)



G1 F50 S1000 M5 (Laser cut through black acrylic, Z0 +15mm from table)


G90 G0 X0 Y0

; M5 enc hole
G121 X0 Y0 R2.1

; M4 flange holes
G121 X+12 Y0 R1.65
G121 X0 Y+12 R1.65
G121 X-12 Y0 R1.65
G121 X0 Y-12 R1.65


; M6 sprocket holes
G121 X+27.5 Y0 R2.5
G121 X0 Y+27.5 R2.5
G121 X-27.5 Y0 R2.5
G121 X0 Y-27.5 R2.5

; Cut out
G121 X0 Y0 R35

;TODO include laser width
; Measured holes: 4.8, 3.9, 5.6

G90 G0 X0 Y0