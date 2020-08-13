.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuScWaitTaskReady
/* 03A520 8005F120 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 03A524 8005F124 3C05800E */  lui   $a1, 0x800e
/* 03A528 8005F128 24A5AABD */  addiu $a1, $a1, -0x5543
/* 03A52C 8005F12C 24030001 */  addiu $v1, $zero, 1
/* 03A530 8005F130 AFBF0034 */  sw    $ra, 0x34($sp)
/* 03A534 8005F134 AFB40030 */  sw    $s4, 0x30($sp)
/* 03A538 8005F138 AFB3002C */  sw    $s3, 0x2c($sp)
/* 03A53C 8005F13C AFB20028 */  sw    $s2, 0x28($sp)
/* 03A540 8005F140 AFB10024 */  sw    $s1, 0x24($sp)
/* 03A544 8005F144 AFB00020 */  sw    $s0, 0x20($sp)
/* 03A548 8005F148 90A20000 */  lbu   $v0, ($a1)
/* 03A54C 8005F14C 8C92000C */  lw    $s2, 0xc($a0)
/* 03A550 8005F150 10430035 */  beq   $v0, $v1, .L8005F228
/* 03A554 8005F154 27B10010 */   addiu $s1, $sp, 0x10
/* 03A558 8005F158 24B4FA9F */  addiu $s4, $a1, -0x561
/* 03A55C 8005F15C 0060982D */  daddu $s3, $v1, $zero
.L8005F160:
/* 03A560 8005F160 0C019A6C */  jal   osViGetCurrentFramebuffer
/* 03A564 8005F164 00000000 */   nop   
/* 03A568 8005F168 10520005 */  beq   $v0, $s2, .L8005F180
/* 03A56C 8005F16C 00000000 */   nop   
/* 03A570 8005F170 0C019A7C */  jal   osViGetNextFramebuffer
/* 03A574 8005F174 00000000 */   nop   
/* 03A578 8005F178 1452002B */  bne   $v0, $s2, .L8005F228
/* 03A57C 8005F17C 00000000 */   nop   
.L8005F180:
/* 03A580 8005F180 0C018250 */  jal   osSetIntMask
/* 03A584 8005F184 24040001 */   addiu $a0, $zero, 1
/* 03A588 8005F188 AE340004 */  sw    $s4, 4($s1)
/* 03A58C 8005F18C 3C03800E */  lui   $v1, 0x800e
/* 03A590 8005F190 8C63AAA8 */  lw    $v1, -0x5558($v1)
/* 03A594 8005F194 AFA30010 */  sw    $v1, 0x10($sp)
/* 03A598 8005F198 A6330008 */  sh    $s3, 8($s1)
/* 03A59C 8005F19C 3C01800E */  lui   $at, 0x800e
/* 03A5A0 8005F1A0 AC31AAA8 */  sw    $s1, -0x5558($at)
/* 03A5A4 8005F1A4 0C018250 */  jal   osSetIntMask
/* 03A5A8 8005F1A8 0040202D */   daddu $a0, $v0, $zero
/* 03A5AC 8005F1AC 3C04800E */  lui   $a0, 0x800e
/* 03A5B0 8005F1B0 2484A55C */  addiu $a0, $a0, -0x5aa4
/* 03A5B4 8005F1B4 0000282D */  daddu $a1, $zero, $zero
/* 03A5B8 8005F1B8 0C0195BC */  jal   osRecvMesg
/* 03A5BC 8005F1BC 24060001 */   addiu $a2, $zero, 1
/* 03A5C0 8005F1C0 0C018250 */  jal   osSetIntMask
/* 03A5C4 8005F1C4 24040001 */   addiu $a0, $zero, 1
/* 03A5C8 8005F1C8 0000282D */  daddu $a1, $zero, $zero
/* 03A5CC 8005F1CC 27B00010 */  addiu $s0, $sp, 0x10
/* 03A5D0 8005F1D0 3C03800E */  lui   $v1, 0x800e
/* 03A5D4 8005F1D4 8C63AAA8 */  lw    $v1, -0x5558($v1)
/* 03A5D8 8005F1D8 1060000C */  beqz  $v1, .L8005F20C
/* 03A5DC 8005F1DC 0040202D */   daddu $a0, $v0, $zero
.L8005F1E0:
/* 03A5E0 8005F1E0 54700007 */  bnel  $v1, $s0, .L8005F200
/* 03A5E4 8005F1E4 0060282D */   daddu $a1, $v1, $zero
/* 03A5E8 8005F1E8 14A0000C */  bnez  $a1, .L8005F21C
/* 03A5EC 8005F1EC 00000000 */   nop   
/* 03A5F0 8005F1F0 8C620000 */  lw    $v0, ($v1)
/* 03A5F4 8005F1F4 3C01800E */  lui   $at, 0x800e
/* 03A5F8 8005F1F8 08017C83 */  j     .L8005F20C
/* 03A5FC 8005F1FC AC22AAA8 */   sw    $v0, -0x5558($at)

.L8005F200:
/* 03A600 8005F200 8CA30000 */  lw    $v1, ($a1)
/* 03A604 8005F204 1460FFF6 */  bnez  $v1, .L8005F1E0
/* 03A608 8005F208 00000000 */   nop   
.L8005F20C:
/* 03A60C 8005F20C 0C018250 */  jal   osSetIntMask
/* 03A610 8005F210 00000000 */   nop   
/* 03A614 8005F214 08017C58 */  j     .L8005F160
/* 03A618 8005F218 00000000 */   nop   

.L8005F21C:
/* 03A61C 8005F21C 8C620000 */  lw    $v0, ($v1)
/* 03A620 8005F220 08017C83 */  j     .L8005F20C
/* 03A624 8005F224 ACA20000 */   sw    $v0, ($a1)

.L8005F228:
/* 03A628 8005F228 8FBF0034 */  lw    $ra, 0x34($sp)
/* 03A62C 8005F22C 8FB40030 */  lw    $s4, 0x30($sp)
/* 03A630 8005F230 8FB3002C */  lw    $s3, 0x2c($sp)
/* 03A634 8005F234 8FB20028 */  lw    $s2, 0x28($sp)
/* 03A638 8005F238 8FB10024 */  lw    $s1, 0x24($sp)
/* 03A63C 8005F23C 8FB00020 */  lw    $s0, 0x20($sp)
/* 03A640 8005F240 03E00008 */  jr    $ra
/* 03A644 8005F244 27BD0038 */   addiu $sp, $sp, 0x38

/* 03A648 8005F248 00000000 */  nop   
/* 03A64C 8005F24C 00000000 */  nop   


