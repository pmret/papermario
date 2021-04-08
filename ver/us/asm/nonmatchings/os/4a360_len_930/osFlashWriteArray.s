.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osFlashWriteArray
/* 4AA1C 8006F61C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4AA20 8006F620 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4AA24 8006F624 AFA40020 */  sw        $a0, 0x20($sp)
/* 4AA28 8006F628 3C0E800B */  lui       $t6, %hi(D_800B0CE8)
/* 4AA2C 8006F62C 8DCE0CE8 */  lw        $t6, %lo(D_800B0CE8)($t6)
/* 4AA30 8006F630 24010001 */  addiu     $at, $zero, 1
/* 4AA34 8006F634 15C1000B */  bne       $t6, $at, .L8006F664
/* 4AA38 8006F638 00000000 */   nop
/* 4AA3C 8006F63C 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4AA40 8006F640 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4AA44 8006F644 3C05800B */  lui       $a1, %hi(D_800B0C7C)
/* 4AA48 8006F648 8CA50C7C */  lw        $a1, %lo(D_800B0C7C)($a1)
/* 4AA4C 8006F64C 3C010001 */  lui       $at, 1
/* 4AA50 8006F650 00A17825 */  or        $t7, $a1, $at
/* 4AA54 8006F654 01E02825 */  or        $a1, $t7, $zero
/* 4AA58 8006F658 3C06B400 */  lui       $a2, 0xb400
/* 4AA5C 8006F65C 0C018358 */  jal       osEPiWriteIo
/* 4AA60 8006F660 00000000 */   nop
.L8006F664:
/* 4AA64 8006F664 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4AA68 8006F668 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4AA6C 8006F66C 3C05800B */  lui       $a1, %hi(D_800B0C7C)
/* 4AA70 8006F670 8CA50C7C */  lw        $a1, %lo(D_800B0C7C)($a1)
/* 4AA74 8006F674 3C010001 */  lui       $at, 1
/* 4AA78 8006F678 00A1C025 */  or        $t8, $a1, $at
/* 4AA7C 8006F67C 03002825 */  or        $a1, $t8, $zero
/* 4AA80 8006F680 8FA60020 */  lw        $a2, 0x20($sp)
/* 4AA84 8006F684 3C01A500 */  lui       $at, 0xa500
/* 4AA88 8006F688 00C1C825 */  or        $t9, $a2, $at
/* 4AA8C 8006F68C 03203025 */  or        $a2, $t9, $zero
/* 4AA90 8006F690 0C018358 */  jal       osEPiWriteIo
/* 4AA94 8006F694 00000000 */   nop
.L8006F698:
/* 4AA98 8006F698 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4AA9C 8006F69C 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4AAA0 8006F6A0 3C05800B */  lui       $a1, %hi(D_800B0C7C)
/* 4AAA4 8006F6A4 8CA50C7C */  lw        $a1, %lo(D_800B0C7C)($a1)
/* 4AAA8 8006F6A8 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4AAAC 8006F6AC 0C018370 */  jal       osEPiReadIo
/* 4AAB0 8006F6B0 00000000 */   nop
/* 4AAB4 8006F6B4 8FA8001C */  lw        $t0, 0x1c($sp)
/* 4AAB8 8006F6B8 00000000 */  nop
/* 4AABC 8006F6BC 31090001 */  andi      $t1, $t0, 1
/* 4AAC0 8006F6C0 24010001 */  addiu     $at, $zero, 1
/* 4AAC4 8006F6C4 1121FFF4 */  beq       $t1, $at, .L8006F698
/* 4AAC8 8006F6C8 00000000 */   nop
/* 4AACC 8006F6CC 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4AAD0 8006F6D0 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4AAD4 8006F6D4 3C05800B */  lui       $a1, %hi(D_800B0C7C)
/* 4AAD8 8006F6D8 8CA50C7C */  lw        $a1, %lo(D_800B0C7C)($a1)
/* 4AADC 8006F6DC 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4AAE0 8006F6E0 0C018370 */  jal       osEPiReadIo
/* 4AAE4 8006F6E4 00000000 */   nop
/* 4AAE8 8006F6E8 0C01BCA7 */  jal       osFlashClearStatus
/* 4AAEC 8006F6EC 00000000 */   nop
/* 4AAF0 8006F6F0 8FAA001C */  lw        $t2, 0x1c($sp)
/* 4AAF4 8006F6F4 00000000 */  nop
/* 4AAF8 8006F6F8 314B00FF */  andi      $t3, $t2, 0xff
/* 4AAFC 8006F6FC 24010004 */  addiu     $at, $zero, 4
/* 4AB00 8006F700 11610008 */  beq       $t3, $at, .L8006F724
/* 4AB04 8006F704 00000000 */   nop
/* 4AB08 8006F708 24010044 */  addiu     $at, $zero, 0x44
/* 4AB0C 8006F70C 11610005 */  beq       $t3, $at, .L8006F724
/* 4AB10 8006F710 00000000 */   nop
/* 4AB14 8006F714 314C0004 */  andi      $t4, $t2, 4
/* 4AB18 8006F718 24010004 */  addiu     $at, $zero, 4
/* 4AB1C 8006F71C 15810006 */  bne       $t4, $at, .L8006F738
/* 4AB20 8006F720 00000000 */   nop
.L8006F724:
/* 4AB24 8006F724 00001025 */  or        $v0, $zero, $zero
/* 4AB28 8006F728 10000008 */  b         .L8006F74C
/* 4AB2C 8006F72C 00000000 */   nop
/* 4AB30 8006F730 10000004 */  b         .L8006F744
/* 4AB34 8006F734 00000000 */   nop
.L8006F738:
/* 4AB38 8006F738 2402FFFF */  addiu     $v0, $zero, -1
/* 4AB3C 8006F73C 10000003 */  b         .L8006F74C
/* 4AB40 8006F740 00000000 */   nop
.L8006F744:
/* 4AB44 8006F744 10000001 */  b         .L8006F74C
/* 4AB48 8006F748 00000000 */   nop
.L8006F74C:
/* 4AB4C 8006F74C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4AB50 8006F750 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4AB54 8006F754 03E00008 */  jr        $ra
/* 4AB58 8006F758 00000000 */   nop
