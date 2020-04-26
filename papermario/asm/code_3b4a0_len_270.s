
.section .text800600A0, "ax"

nuContRmbForceStop:
/* 03B4A0 800600A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B4A4 800600A4 24040304 */  addiu $a0, $zero, 0x304
/* 03B4A8 800600A8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B4AC 800600AC 0C00B3CA */  jal   func_8002CF28
/* 03B4B0 800600B0 0000282D */   daddu $a1, $zero, $zero
/* 03B4B4 800600B4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B4B8 800600B8 03E00008 */  jr    $ra
/* 03B4BC 800600BC 27BD0018 */   addiu $sp, $sp, 0x18

nuContRmbForceStopEnd:
/* 03B4C0 800600C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B4C4 800600C4 24040305 */  addiu $a0, $zero, 0x305
/* 03B4C8 800600C8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B4CC 800600CC 0C00B3CA */  jal   func_8002CF28
/* 03B4D0 800600D0 0000282D */   daddu $a1, $zero, $zero
/* 03B4D4 800600D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B4D8 800600D8 03E00008 */  jr    $ra
/* 03B4DC 800600DC 27BD0018 */   addiu $sp, $sp, 0x18

nuPiReadRomOverlay:
/* 03B4E0 800600E0 27BDFF98 */  addiu $sp, $sp, -0x68
/* 03B4E4 800600E4 AFB40058 */  sw    $s4, 0x58($sp)
/* 03B4E8 800600E8 0080A02D */  daddu $s4, $a0, $zero
/* 03B4EC 800600EC AFB5005C */  sw    $s5, 0x5c($sp)
/* 03B4F0 800600F0 24150001 */  addiu $s5, $zero, 1
/* 03B4F4 800600F4 AFB00048 */  sw    $s0, 0x48($sp)
/* 03B4F8 800600F8 27B00028 */  addiu $s0, $sp, 0x28
/* 03B4FC 800600FC 0200202D */  daddu $a0, $s0, $zero
/* 03B500 80060100 27A50040 */  addiu $a1, $sp, 0x40
/* 03B504 80060104 02A0302D */  daddu $a2, $s5, $zero
/* 03B508 80060108 AFBF0060 */  sw    $ra, 0x60($sp)
/* 03B50C 8006010C AFB30054 */  sw    $s3, 0x54($sp)
/* 03B510 80060110 AFB20050 */  sw    $s2, 0x50($sp)
/* 03B514 80060114 0C019560 */  jal   osCreateMesgQueue
/* 03B518 80060118 AFB1004C */   sw    $s1, 0x4c($sp)
/* 03B51C 8006011C A3A00012 */  sb    $zero, 0x12($sp)
/* 03B520 80060120 AFB00014 */  sw    $s0, 0x14($sp)
/* 03B524 80060124 8E840014 */  lw    $a0, 0x14($s4)
/* 03B528 80060128 8E850018 */  lw    $a1, 0x18($s4)
/* 03B52C 8006012C 0C0185C8 */  jal   osInvalDCache
/* 03B530 80060130 00A42823 */   subu  $a1, $a1, $a0
/* 03B534 80060134 8E84000C */  lw    $a0, 0xc($s4)
/* 03B538 80060138 8E850010 */  lw    $a1, 0x10($s4)
/* 03B53C 8006013C 0C0185F4 */  jal   osInvalICache
/* 03B540 80060140 00A42823 */   subu  $a1, $a1, $a0
/* 03B544 80060144 8E920000 */  lw    $s2, ($s4)
/* 03B548 80060148 8E820004 */  lw    $v0, 4($s4)
/* 03B54C 8006014C 8E930008 */  lw    $s3, 8($s4)
/* 03B550 80060150 00528823 */  subu  $s1, $v0, $s2
/* 03B554 80060154 1220001C */  beqz  $s1, .L800601C8
/* 03B558 80060158 00000000 */   nop   
.L8006015C:
/* 03B55C 8006015C 2E224001 */  sltiu $v0, $s1, 0x4001
/* 03B560 80060160 14400002 */  bnez  $v0, .L8006016C
/* 03B564 80060164 0220802D */   daddu $s0, $s1, $zero
/* 03B568 80060168 24104000 */  addiu $s0, $zero, 0x4000
.L8006016C:
/* 03B56C 8006016C 27A50010 */  addiu $a1, $sp, 0x10
/* 03B570 80060170 3C04800A */  lui   $a0, 0x800a
/* 03B574 80060174 8C84A638 */  lw    $a0, -0x59c8($a0)
/* 03B578 80060178 0000302D */  daddu $a2, $zero, $zero
/* 03B57C 8006017C AFB30018 */  sw    $s3, 0x18($sp)
/* 03B580 80060180 AFB2001C */  sw    $s2, 0x1c($sp)
/* 03B584 80060184 0C018388 */  jal   osEPiStartDma
/* 03B588 80060188 AFB00020 */   sw    $s0, 0x20($sp)
/* 03B58C 8006018C 12A00007 */  beqz  $s5, .L800601AC
/* 03B590 80060190 27A40028 */   addiu $a0, $sp, 0x28
/* 03B594 80060194 8E84001C */  lw    $a0, 0x1c($s4)
/* 03B598 80060198 8E850020 */  lw    $a1, 0x20($s4)
/* 03B59C 8006019C 0000A82D */  daddu $s5, $zero, $zero
/* 03B5A0 800601A0 0C01925C */  jal   bzero
/* 03B5A4 800601A4 00A42823 */   subu  $a1, $a1, $a0
/* 03B5A8 800601A8 27A40028 */  addiu $a0, $sp, 0x28
.L800601AC:
/* 03B5AC 800601AC 27A50040 */  addiu $a1, $sp, 0x40
/* 03B5B0 800601B0 0C0195BC */  jal   osRecvMesg
/* 03B5B4 800601B4 24060001 */   addiu $a2, $zero, 1
/* 03B5B8 800601B8 02509021 */  addu  $s2, $s2, $s0
/* 03B5BC 800601BC 02308823 */  subu  $s1, $s1, $s0
/* 03B5C0 800601C0 1620FFE6 */  bnez  $s1, .L8006015C
/* 03B5C4 800601C4 02709821 */   addu  $s3, $s3, $s0
.L800601C8:
/* 03B5C8 800601C8 8FBF0060 */  lw    $ra, 0x60($sp)
/* 03B5CC 800601CC 8FB5005C */  lw    $s5, 0x5c($sp)
/* 03B5D0 800601D0 8FB40058 */  lw    $s4, 0x58($sp)
/* 03B5D4 800601D4 8FB30054 */  lw    $s3, 0x54($sp)
/* 03B5D8 800601D8 8FB20050 */  lw    $s2, 0x50($sp)
/* 03B5DC 800601DC 8FB1004C */  lw    $s1, 0x4c($sp)
/* 03B5E0 800601E0 8FB00048 */  lw    $s0, 0x48($sp)
/* 03B5E4 800601E4 03E00008 */  jr    $ra
/* 03B5E8 800601E8 27BD0068 */   addiu $sp, $sp, 0x68

/* 03B5EC 800601EC 00000000 */  nop   
nuGfxThreadStart:
/* 03B5F0 800601F0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03B5F4 800601F4 AFB00018 */  sw    $s0, 0x18($sp)
/* 03B5F8 800601F8 3C10800B */  lui   $s0, 0x800b
/* 03B5FC 800601FC 26101B90 */  addiu $s0, $s0, 0x1b90
/* 03B600 80060200 0200202D */  daddu $a0, $s0, $zero
/* 03B604 80060204 3C02800B */  lui   $v0, 0x800b
/* 03B608 80060208 2442E6D0 */  addiu $v0, $v0, -0x1930
/* 03B60C 8006020C AFA20010 */  sw    $v0, 0x10($sp)
/* 03B610 80060210 24020032 */  addiu $v0, $zero, 0x32
/* 03B614 80060214 24050004 */  addiu $a1, $zero, 4
/* 03B618 80060218 3C068006 */  lui   $a2, 0x8006
/* 03B61C 8006021C 24C60248 */  addiu $a2, $a2, 0x248
/* 03B620 80060220 0000382D */  daddu $a3, $zero, $zero
/* 03B624 80060224 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03B628 80060228 0C019798 */  jal   osCreateThread
/* 03B62C 8006022C AFA20014 */   sw    $v0, 0x14($sp)
/* 03B630 80060230 0C019808 */  jal   osStartThread
/* 03B634 80060234 0200202D */   daddu $a0, $s0, $zero
/* 03B638 80060238 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03B63C 8006023C 8FB00018 */  lw    $s0, 0x18($sp)
/* 03B640 80060240 03E00008 */  jr    $ra
/* 03B644 80060244 27BD0020 */   addiu $sp, $sp, 0x20

nuGfxThread:
/* 03B648 80060248 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 03B64C 8006024C AFB00028 */  sw    $s0, 0x28($sp)
/* 03B650 80060250 3C10800B */  lui   $s0, 0x800b
/* 03B654 80060254 261042F0 */  addiu $s0, $s0, 0x42f0
/* 03B658 80060258 0200202D */  daddu $a0, $s0, $zero
/* 03B65C 8006025C 3C05800B */  lui   $a1, 0x800b
/* 03B660 80060260 24A5C6B0 */  addiu $a1, $a1, -0x3950
/* 03B664 80060264 24060008 */  addiu $a2, $zero, 8
/* 03B668 80060268 AFBF0030 */  sw    $ra, 0x30($sp)
/* 03B66C 8006026C 0C019560 */  jal   osCreateMesgQueue
/* 03B670 80060270 AFB1002C */   sw    $s1, 0x2c($sp)
/* 03B674 80060274 27A40010 */  addiu $a0, $sp, 0x10
/* 03B678 80060278 0200282D */  daddu $a1, $s0, $zero
/* 03B67C 8006027C 0C017B8C */  jal   nuScAddClient
/* 03B680 80060280 24060003 */   addiu $a2, $zero, 3
/* 03B684 80060284 24110001 */  addiu $s1, $zero, 1
/* 03B688 80060288 24100002 */  addiu $s0, $zero, 2
func_8006028C:
.L8006028C:
/* 03B68C 8006028C 3C04800B */  lui   $a0, 0x800b
/* 03B690 80060290 248442F0 */  addiu $a0, $a0, 0x42f0
/* 03B694 80060294 27A50020 */  addiu $a1, $sp, 0x20
/* 03B698 80060298 0C0195BC */  jal   osRecvMesg
/* 03B69C 8006029C 24060001 */   addiu $a2, $zero, 1
/* 03B6A0 800602A0 8FA20020 */  lw    $v0, 0x20($sp)
/* 03B6A4 800602A4 84420000 */  lh    $v0, ($v0)
/* 03B6A8 800602A8 10510005 */  beq   $v0, $s1, .L800602C0
/* 03B6AC 800602AC 00000000 */   nop   
/* 03B6B0 800602B0 1050000D */  beq   $v0, $s0, .L800602E8
/* 03B6B4 800602B4 00000000 */   nop   
/* 03B6B8 800602B8 080180A3 */  j     func_8006028C
/* 03B6BC 800602BC 00000000 */   nop   

.L800602C0:
/* 03B6C0 800602C0 3C028009 */  lui   $v0, 0x8009
/* 03B6C4 800602C4 8C423D10 */  lw    $v0, 0x3d10($v0)
/* 03B6C8 800602C8 1040FFF0 */  beqz  $v0, .L8006028C
/* 03B6CC 800602CC 00000000 */   nop   
/* 03B6D0 800602D0 3C04800A */  lui   $a0, 0x800a
/* 03B6D4 800602D4 8C84A618 */  lw    $a0, -0x59e8($a0)
/* 03B6D8 800602D8 0040F809 */  jalr  $v0
/* 03B6DC 800602DC 00000000 */  nop   
/* 03B6E0 800602E0 080180A3 */  j     func_8006028C
/* 03B6E4 800602E4 00000000 */   nop   

.L800602E8:
/* 03B6E8 800602E8 3C028009 */  lui   $v0, 0x8009
/* 03B6EC 800602EC 8C423D14 */  lw    $v0, 0x3d14($v0)
/* 03B6F0 800602F0 1040FFE6 */  beqz  $v0, .L8006028C
/* 03B6F4 800602F4 00000000 */   nop   
/* 03B6F8 800602F8 0040F809 */  jalr  $v0
/* 03B6FC 800602FC 00000000 */  nop   
/* 03B700 80060300 080180A3 */  j     func_8006028C
/* 03B704 80060304 00000000 */   nop   

/* 03B708 80060308 00000000 */  nop   
/* 03B70C 8006030C 00000000 */  nop   
