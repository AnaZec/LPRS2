G90 G0 X0 Y0 Z0 (Must have this on start)



G1 F50 S1000 M5 (Laser cut through black acrylic, Z0 +15mm from table)


G90 G0 X0 Y0

; Laser width correction
; R = (D_tap_drill - 0.6) / 2
; M3 2.5 0.95
; M4 3.3 1.35
; M5 4.2 1.8
; M6 5.0 2.2
; M8 6.8 3.25

; M5 enc hole
G121 X0 Y0 R1.8

; M4 flange holes
G121 X+12 Y0 R1.35
G121 X0 Y+12 R1.35
G121 X-12 Y0 R1.35
G121 X0 Y-12 R1.35


; M6 sprocket holes
G121 X+27.5 Y0 R3.25
G121 X0 Y+27.5 R3.25
G121 X-27.5 Y0 R3.25
G121 X0 Y-27.5 R3.25

; Cut out
G121 X0 Y0 R35

;TODO include laser width
; Measured holes: 4.8, 3.9, 5.6

G90 G0 X0 Y0