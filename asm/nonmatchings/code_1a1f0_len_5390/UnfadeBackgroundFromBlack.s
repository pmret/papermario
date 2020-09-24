.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnfadeBackgroundFromBlack
/* 1A398 8003EF98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A39C 8003EF9C AFB00010 */  sw        $s0, 0x10($sp)
/* 1A3A0 8003EFA0 0080802D */  daddu     $s0, $a0, $zero
/* 1A3A4 8003EFA4 10A00003 */  beqz      $a1, .L8003EFB4
/* 1A3A8 8003EFA8 AFBF0014 */   sw       $ra, 0x14($sp)
/* 1A3AC 8003EFAC 24020019 */  addiu     $v0, $zero, 0x19
/* 1A3B0 8003EFB0 AE020070 */  sw        $v0, 0x70($s0)
.L8003EFB4:
/* 1A3B4 8003EFB4 0000202D */  daddu     $a0, $zero, $zero
/* 1A3B8 8003EFB8 0080282D */  daddu     $a1, $a0, $zero
/* 1A3BC 8003EFBC 8E020070 */  lw        $v0, 0x70($s0)
/* 1A3C0 8003EFC0 0080302D */  daddu     $a2, $a0, $zero
/* 1A3C4 8003EFC4 00023880 */  sll       $a3, $v0, 2
/* 1A3C8 8003EFC8 00E23821 */  addu      $a3, $a3, $v0
/* 1A3CC 8003EFCC 00073840 */  sll       $a3, $a3, 1
/* 1A3D0 8003EFD0 0C046F97 */  jal       set_background_color_blend
/* 1A3D4 8003EFD4 30E700FE */   andi     $a3, $a3, 0xfe
/* 1A3D8 8003EFD8 8E020070 */  lw        $v0, 0x70($s0)
/* 1A3DC 8003EFDC 2442FFFB */  addiu     $v0, $v0, -5
/* 1A3E0 8003EFE0 10400003 */  beqz      $v0, .L8003EFF0
/* 1A3E4 8003EFE4 AE020070 */   sw       $v0, 0x70($s0)
/* 1A3E8 8003EFE8 0800FC02 */  j         .L8003F008
/* 1A3EC 8003EFEC 0000102D */   daddu    $v0, $zero, $zero
.L8003EFF0:
/* 1A3F0 8003EFF0 0000202D */  daddu     $a0, $zero, $zero
/* 1A3F4 8003EFF4 0080282D */  daddu     $a1, $a0, $zero
/* 1A3F8 8003EFF8 0080302D */  daddu     $a2, $a0, $zero
/* 1A3FC 8003EFFC 0C046F97 */  jal       set_background_color_blend
/* 1A400 8003F000 0080382D */   daddu    $a3, $a0, $zero
/* 1A404 8003F004 24020002 */  addiu     $v0, $zero, 2
.L8003F008:
/* 1A408 8003F008 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1A40C 8003F00C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A410 8003F010 03E00008 */  jr        $ra
/* 1A414 8003F014 27BD0018 */   addiu    $sp, $sp, 0x18
