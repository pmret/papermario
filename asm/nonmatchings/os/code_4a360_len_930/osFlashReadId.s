.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osFlashReadId
/* 04A584 8006F184 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04A588 8006F188 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04A58C 8006F18C AFA40020 */  sw    $a0, 0x20($sp)
/* 04A590 8006F190 AFA50024 */  sw    $a1, 0x24($sp)
/* 04A594 8006F194 27A4001F */  addiu $a0, $sp, 0x1f
/* 04A598 8006F198 0C01BC2E */  jal   osFlashReadStatus
/* 04A59C 8006F19C 00000000 */   nop   
/* 04A5A0 8006F1A0 3C04800B */  lui   $a0, 0x800b
/* 04A5A4 8006F1A4 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A5A8 8006F1A8 3C05800B */  lui   $a1, 0x800b
/* 04A5AC 8006F1AC 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A5B0 8006F1B0 3C010001 */  lui   $at, 1
/* 04A5B4 8006F1B4 00A17025 */  or    $t6, $a1, $at
/* 04A5B8 8006F1B8 01C02825 */  or    $a1, $t6, $zero
/* 04A5BC 8006F1BC 3C06E100 */  lui   $a2, 0xe100
/* 04A5C0 8006F1C0 0C018358 */  jal   osEPiWriteIo
/* 04A5C4 8006F1C4 00000000 */   nop   
/* 04A5C8 8006F1C8 3C01800B */  lui   $at, 0x800b
/* 04A5CC 8006F1CC A0200C42 */  sb    $zero, 0xc42($at)
/* 04A5D0 8006F1D0 3C0F800B */  lui   $t7, 0x800b
/* 04A5D4 8006F1D4 25EF0C58 */  addiu $t7, $t7, 0xc58
/* 04A5D8 8006F1D8 3C01800B */  lui   $at, 0x800b
/* 04A5DC 8006F1DC AC2F0C44 */  sw    $t7, 0xc44($at)
/* 04A5E0 8006F1E0 3C18800B */  lui   $t8, 0x800b
/* 04A5E4 8006F1E4 27180C30 */  addiu $t8, $t8, 0xc30
/* 04A5E8 8006F1E8 3C01800B */  lui   $at, 0x800b
/* 04A5EC 8006F1EC AC380C48 */  sw    $t8, 0xc48($at)
/* 04A5F0 8006F1F0 3C01800B */  lui   $at, 0x800b
/* 04A5F4 8006F1F4 AC200C4C */  sw    $zero, 0xc4c($at)
/* 04A5F8 8006F1F8 24190008 */  addiu $t9, $zero, 8
/* 04A5FC 8006F1FC 3C01800B */  lui   $at, 0x800b
/* 04A600 8006F200 AC390C50 */  sw    $t9, 0xc50($at)
/* 04A604 8006F204 3C04800B */  lui   $a0, 0x800b
/* 04A608 8006F208 24840C30 */  addiu $a0, $a0, 0xc30
/* 04A60C 8006F20C 24050010 */  addiu $a1, $zero, 0x10
/* 04A610 8006F210 0C018614 */  jal   osWritebackDCache
/* 04A614 8006F214 00000000 */   nop   
/* 04A618 8006F218 3C04800B */  lui   $a0, 0x800b
/* 04A61C 8006F21C 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A620 8006F220 3C05800B */  lui   $a1, 0x800b
/* 04A624 8006F224 24A50C40 */  addiu $a1, $a1, 0xc40
/* 04A628 8006F228 00003025 */  or    $a2, $zero, $zero
/* 04A62C 8006F22C 0C018388 */  jal   osEPiStartDma
/* 04A630 8006F230 00000000 */   nop   
/* 04A634 8006F234 3C04800B */  lui   $a0, 0x800b
/* 04A638 8006F238 24840C58 */  addiu $a0, $a0, 0xc58
/* 04A63C 8006F23C 00002825 */  or    $a1, $zero, $zero
/* 04A640 8006F240 24060001 */  addiu $a2, $zero, 1
/* 04A644 8006F244 0C0195BC */  jal   osRecvMesg
/* 04A648 8006F248 00000000 */   nop   
/* 04A64C 8006F24C 3C08800B */  lui   $t0, 0x800b
/* 04A650 8006F250 25080C30 */  addiu $t0, $t0, 0xc30
/* 04A654 8006F254 8D090000 */  lw    $t1, ($t0)
/* 04A658 8006F258 8FAA0020 */  lw    $t2, 0x20($sp)
/* 04A65C 8006F25C 00000000 */  nop   
/* 04A660 8006F260 AD490000 */  sw    $t1, ($t2)
/* 04A664 8006F264 3C0B800B */  lui   $t3, 0x800b
/* 04A668 8006F268 256B0C30 */  addiu $t3, $t3, 0xc30
/* 04A66C 8006F26C 8D6C0004 */  lw    $t4, 4($t3)
/* 04A670 8006F270 8FAD0024 */  lw    $t5, 0x24($sp)
/* 04A674 8006F274 00000000 */  nop   
/* 04A678 8006F278 ADAC0000 */  sw    $t4, ($t5)
/* 04A67C 8006F27C 10000003 */  b     .L8006F28C
/* 04A680 8006F280 00000000 */   nop   
/* 04A684 8006F284 10000001 */  b     .L8006F28C
/* 04A688 8006F288 00000000 */   nop   
.L8006F28C:
/* 04A68C 8006F28C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04A690 8006F290 27BD0020 */  addiu $sp, $sp, 0x20
/* 04A694 8006F294 03E00008 */  jr    $ra
/* 04A698 8006F298 00000000 */   nop   

