.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FD90
/* 3B190 8005FD90 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 3B194 8005FD94 AFB40058 */  sw        $s4, 0x58($sp)
/* 3B198 8005FD98 0080A02D */  daddu     $s4, $a0, $zero
/* 3B19C 8005FD9C AFB5005C */  sw        $s5, 0x5c($sp)
/* 3B1A0 8005FDA0 24150001 */  addiu     $s5, $zero, 1
/* 3B1A4 8005FDA4 AFB00048 */  sw        $s0, 0x48($sp)
/* 3B1A8 8005FDA8 27B00028 */  addiu     $s0, $sp, 0x28
/* 3B1AC 8005FDAC 0200202D */  daddu     $a0, $s0, $zero
/* 3B1B0 8005FDB0 27A50040 */  addiu     $a1, $sp, 0x40
/* 3B1B4 8005FDB4 02A0302D */  daddu     $a2, $s5, $zero
/* 3B1B8 8005FDB8 AFBF0060 */  sw        $ra, 0x60($sp)
/* 3B1BC 8005FDBC AFB30054 */  sw        $s3, 0x54($sp)
/* 3B1C0 8005FDC0 AFB20050 */  sw        $s2, 0x50($sp)
/* 3B1C4 8005FDC4 0C019554 */  jal       func_80065550
/* 3B1C8 8005FDC8 AFB1004C */   sw       $s1, 0x4c($sp)
/* 3B1CC 8005FDCC A3A00012 */  sb        $zero, 0x12($sp)
/* 3B1D0 8005FDD0 AFB00014 */  sw        $s0, 0x14($sp)
/* 3B1D4 8005FDD4 8E840014 */  lw        $a0, 0x14($s4)
/* 3B1D8 8005FDD8 8E850018 */  lw        $a1, 0x18($s4)
/* 3B1DC 8005FDDC 0C0185BC */  jal       func_800616F0
/* 3B1E0 8005FDE0 00A42823 */   subu     $a1, $a1, $a0
/* 3B1E4 8005FDE4 8E84000C */  lw        $a0, 0xc($s4)
/* 3B1E8 8005FDE8 8E850010 */  lw        $a1, 0x10($s4)
/* 3B1EC 8005FDEC 0C0185E8 */  jal       func_800617A0
/* 3B1F0 8005FDF0 00A42823 */   subu     $a1, $a1, $a0
/* 3B1F4 8005FDF4 8E920000 */  lw        $s2, ($s4)
/* 3B1F8 8005FDF8 8E820004 */  lw        $v0, 4($s4)
/* 3B1FC 8005FDFC 8E930008 */  lw        $s3, 8($s4)
/* 3B200 8005FE00 00528823 */  subu      $s1, $v0, $s2
/* 3B204 8005FE04 1220001C */  beqz      $s1, .L8005FE78
/* 3B208 8005FE08 00000000 */   nop
.L8005FE0C:
/* 3B20C 8005FE0C 2E224001 */  sltiu     $v0, $s1, 0x4001
/* 3B210 8005FE10 14400002 */  bnez      $v0, .L8005FE1C
/* 3B214 8005FE14 0220802D */   daddu    $s0, $s1, $zero
/* 3B218 8005FE18 24104000 */  addiu     $s0, $zero, 0x4000
.L8005FE1C:
/* 3B21C 8005FE1C 27A50010 */  addiu     $a1, $sp, 0x10
/* 3B220 8005FE20 3C04800A */  lui       $a0, %hi(D_8009A618)
/* 3B224 8005FE24 8C84A618 */  lw        $a0, %lo(D_8009A618)($a0)
/* 3B228 8005FE28 0000302D */  daddu     $a2, $zero, $zero
/* 3B22C 8005FE2C AFB30018 */  sw        $s3, 0x18($sp)
/* 3B230 8005FE30 AFB2001C */  sw        $s2, 0x1c($sp)
/* 3B234 8005FE34 0C01837C */  jal       func_80060DF0
/* 3B238 8005FE38 AFB00020 */   sw       $s0, 0x20($sp)
/* 3B23C 8005FE3C 12A00007 */  beqz      $s5, .L8005FE5C
/* 3B240 8005FE40 27A40028 */   addiu    $a0, $sp, 0x28
/* 3B244 8005FE44 8E84001C */  lw        $a0, 0x1c($s4)
/* 3B248 8005FE48 8E850020 */  lw        $a1, 0x20($s4)
/* 3B24C 8005FE4C 0000A82D */  daddu     $s5, $zero, $zero
/* 3B250 8005FE50 0C019250 */  jal       func_80064940
/* 3B254 8005FE54 00A42823 */   subu     $a1, $a1, $a0
/* 3B258 8005FE58 27A40028 */  addiu     $a0, $sp, 0x28
.L8005FE5C:
/* 3B25C 8005FE5C 27A50040 */  addiu     $a1, $sp, 0x40
/* 3B260 8005FE60 0C0195B0 */  jal       func_800656C0
/* 3B264 8005FE64 24060001 */   addiu    $a2, $zero, 1
/* 3B268 8005FE68 02509021 */  addu      $s2, $s2, $s0
/* 3B26C 8005FE6C 02308823 */  subu      $s1, $s1, $s0
/* 3B270 8005FE70 1620FFE6 */  bnez      $s1, .L8005FE0C
/* 3B274 8005FE74 02709821 */   addu     $s3, $s3, $s0
.L8005FE78:
/* 3B278 8005FE78 8FBF0060 */  lw        $ra, 0x60($sp)
/* 3B27C 8005FE7C 8FB5005C */  lw        $s5, 0x5c($sp)
/* 3B280 8005FE80 8FB40058 */  lw        $s4, 0x58($sp)
/* 3B284 8005FE84 8FB30054 */  lw        $s3, 0x54($sp)
/* 3B288 8005FE88 8FB20050 */  lw        $s2, 0x50($sp)
/* 3B28C 8005FE8C 8FB1004C */  lw        $s1, 0x4c($sp)
/* 3B290 8005FE90 8FB00048 */  lw        $s0, 0x48($sp)
/* 3B294 8005FE94 03E00008 */  jr        $ra
/* 3B298 8005FE98 27BD0068 */   addiu    $sp, $sp, 0x68
/* 3B29C 8005FE9C 00000000 */  nop
