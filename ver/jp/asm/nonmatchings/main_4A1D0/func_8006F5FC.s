.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F5FC
/* 4A9FC 8006F5FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4AA00 8006F600 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4AA04 8006F604 AFA40020 */  sw        $a0, 0x20($sp)
/* 4AA08 8006F608 3C0E800B */  lui       $t6, %hi(D_800B0CC8)
/* 4AA0C 8006F60C 8DCE0CC8 */  lw        $t6, %lo(D_800B0CC8)($t6)
/* 4AA10 8006F610 24010001 */  addiu     $at, $zero, 1
/* 4AA14 8006F614 15C1000B */  bne       $t6, $at, .L8006F644
/* 4AA18 8006F618 00000000 */   nop
/* 4AA1C 8006F61C 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AA20 8006F620 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AA24 8006F624 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4AA28 8006F628 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4AA2C 8006F62C 3C010001 */  lui       $at, 1
/* 4AA30 8006F630 00A17825 */  or        $t7, $a1, $at
/* 4AA34 8006F634 01E02825 */  or        $a1, $t7, $zero
/* 4AA38 8006F638 3C06B400 */  lui       $a2, 0xb400
/* 4AA3C 8006F63C 0C01834C */  jal       osEPiWriteIo
/* 4AA40 8006F640 00000000 */   nop
.L8006F644:
/* 4AA44 8006F644 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AA48 8006F648 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AA4C 8006F64C 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4AA50 8006F650 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4AA54 8006F654 3C010001 */  lui       $at, 1
/* 4AA58 8006F658 00A1C025 */  or        $t8, $a1, $at
/* 4AA5C 8006F65C 03002825 */  or        $a1, $t8, $zero
/* 4AA60 8006F660 8FA60020 */  lw        $a2, 0x20($sp)
/* 4AA64 8006F664 3C01A500 */  lui       $at, 0xa500
/* 4AA68 8006F668 00C1C825 */  or        $t9, $a2, $at
/* 4AA6C 8006F66C 03203025 */  or        $a2, $t9, $zero
/* 4AA70 8006F670 0C01834C */  jal       osEPiWriteIo
/* 4AA74 8006F674 00000000 */   nop
.L8006F678:
/* 4AA78 8006F678 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AA7C 8006F67C 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AA80 8006F680 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4AA84 8006F684 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4AA88 8006F688 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4AA8C 8006F68C 0C018364 */  jal       osEPiReadIo
/* 4AA90 8006F690 00000000 */   nop
/* 4AA94 8006F694 8FA8001C */  lw        $t0, 0x1c($sp)
/* 4AA98 8006F698 00000000 */  nop
/* 4AA9C 8006F69C 31090001 */  andi      $t1, $t0, 1
/* 4AAA0 8006F6A0 24010001 */  addiu     $at, $zero, 1
/* 4AAA4 8006F6A4 1121FFF4 */  beq       $t1, $at, .L8006F678
/* 4AAA8 8006F6A8 00000000 */   nop
/* 4AAAC 8006F6AC 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AAB0 8006F6B0 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AAB4 8006F6B4 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4AAB8 8006F6B8 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4AABC 8006F6BC 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4AAC0 8006F6C0 0C018364 */  jal       osEPiReadIo
/* 4AAC4 8006F6C4 00000000 */   nop
/* 4AAC8 8006F6C8 0C01BC9F */  jal       func_8006F27C
/* 4AACC 8006F6CC 00000000 */   nop
/* 4AAD0 8006F6D0 8FAA001C */  lw        $t2, 0x1c($sp)
/* 4AAD4 8006F6D4 00000000 */  nop
/* 4AAD8 8006F6D8 314B00FF */  andi      $t3, $t2, 0xff
/* 4AADC 8006F6DC 24010004 */  addiu     $at, $zero, 4
/* 4AAE0 8006F6E0 11610008 */  beq       $t3, $at, .L8006F704
/* 4AAE4 8006F6E4 00000000 */   nop
/* 4AAE8 8006F6E8 24010044 */  addiu     $at, $zero, 0x44
/* 4AAEC 8006F6EC 11610005 */  beq       $t3, $at, .L8006F704
/* 4AAF0 8006F6F0 00000000 */   nop
/* 4AAF4 8006F6F4 314C0004 */  andi      $t4, $t2, 4
/* 4AAF8 8006F6F8 24010004 */  addiu     $at, $zero, 4
/* 4AAFC 8006F6FC 15810006 */  bne       $t4, $at, .L8006F718
/* 4AB00 8006F700 00000000 */   nop
.L8006F704:
/* 4AB04 8006F704 00001025 */  or        $v0, $zero, $zero
/* 4AB08 8006F708 10000008 */  b         .L8006F72C
/* 4AB0C 8006F70C 00000000 */   nop
/* 4AB10 8006F710 10000004 */  b         .L8006F724
/* 4AB14 8006F714 00000000 */   nop
.L8006F718:
/* 4AB18 8006F718 2402FFFF */  addiu     $v0, $zero, -1
/* 4AB1C 8006F71C 10000003 */  b         .L8006F72C
/* 4AB20 8006F720 00000000 */   nop
.L8006F724:
/* 4AB24 8006F724 10000001 */  b         .L8006F72C
/* 4AB28 8006F728 00000000 */   nop
.L8006F72C:
/* 4AB2C 8006F72C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4AB30 8006F730 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4AB34 8006F734 03E00008 */  jr        $ra
/* 4AB38 8006F738 00000000 */   nop
