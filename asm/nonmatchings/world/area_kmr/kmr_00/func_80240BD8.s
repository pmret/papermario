.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD8
/* 8ACB68 80240BD8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8ACB6C 80240BDC AFB1001C */  sw        $s1, 0x1c($sp)
/* 8ACB70 80240BE0 0080882D */  daddu     $s1, $a0, $zero
/* 8ACB74 80240BE4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8ACB78 80240BE8 AFB00018 */  sw        $s0, 0x18($sp)
/* 8ACB7C 80240BEC 10A0001D */  beqz      $a1, .L80240C64
/* 8ACB80 80240BF0 8E22000C */   lw       $v0, 0xc($s1)
/* 8ACB84 80240BF4 0C0B1EAF */  jal       get_variable
/* 8ACB88 80240BF8 8C450000 */   lw       $a1, ($v0)
/* 8ACB8C 80240BFC 0040202D */  daddu     $a0, $v0, $zero
/* 8ACB90 80240C00 0C00EABB */  jal       get_npc_unsafe
/* 8ACB94 80240C04 AE240074 */   sw       $a0, 0x74($s1)
/* 8ACB98 80240C08 0040802D */  daddu     $s0, $v0, $zero
/* 8ACB9C 80240C0C 3C04B000 */  lui       $a0, 0xb000
/* 8ACBA0 80240C10 C6000040 */  lwc1      $f0, 0x40($s0)
/* 8ACBA4 80240C14 3484001E */  ori       $a0, $a0, 0x1e
/* 8ACBA8 80240C18 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8ACBAC 80240C1C 8E060038 */  lw        $a2, 0x38($s0)
/* 8ACBB0 80240C20 8E07003C */  lw        $a3, 0x3c($s0)
/* 8ACBB4 80240C24 0C052757 */  jal       play_sound_at_position
/* 8ACBB8 80240C28 0000282D */   daddu    $a1, $zero, $zero
/* 8ACBBC 80240C2C C604003C */  lwc1      $f4, 0x3c($s0)
/* 8ACBC0 80240C30 3C0141A0 */  lui       $at, 0x41a0
/* 8ACBC4 80240C34 44810000 */  mtc1      $at, $f0
/* 8ACBC8 80240C38 3C014120 */  lui       $at, 0x4120
/* 8ACBCC 80240C3C 44811000 */  mtc1      $at, $f2
/* 8ACBD0 80240C40 46002100 */  add.s     $f4, $f4, $f0
/* 8ACBD4 80240C44 E7A20010 */  swc1      $f2, 0x10($sp)
/* 8ACBD8 80240C48 8E050038 */  lw        $a1, 0x38($s0)
/* 8ACBDC 80240C4C 8E070040 */  lw        $a3, 0x40($s0)
/* 8ACBE0 80240C50 44062000 */  mfc1      $a2, $f4
/* 8ACBE4 80240C54 0C01BFBC */  jal       func_8006FEF0
/* 8ACBE8 80240C58 0000202D */   daddu    $a0, $zero, $zero
/* 8ACBEC 80240C5C 24020003 */  addiu     $v0, $zero, 3
/* 8ACBF0 80240C60 AE220070 */  sw        $v0, 0x70($s1)
.L80240C64:
/* 8ACBF4 80240C64 0C00EABB */  jal       get_npc_unsafe
/* 8ACBF8 80240C68 8E240074 */   lw       $a0, 0x74($s1)
/* 8ACBFC 80240C6C 0040802D */  daddu     $s0, $v0, $zero
/* 8ACC00 80240C70 8E230070 */  lw        $v1, 0x70($s1)
/* 8ACC04 80240C74 2402FFFF */  addiu     $v0, $zero, -1
/* 8ACC08 80240C78 2463FFFF */  addiu     $v1, $v1, -1
/* 8ACC0C 80240C7C 10620003 */  beq       $v1, $v0, .L80240C8C
/* 8ACC10 80240C80 AE230070 */   sw       $v1, 0x70($s1)
/* 8ACC14 80240C84 08090327 */  j         .L80240C9C
/* 8ACC18 80240C88 0000102D */   daddu    $v0, $zero, $zero
.L80240C8C:
/* 8ACC1C 80240C8C 3C01C47A */  lui       $at, 0xc47a
/* 8ACC20 80240C90 44810000 */  mtc1      $at, $f0
/* 8ACC24 80240C94 24020002 */  addiu     $v0, $zero, 2
/* 8ACC28 80240C98 E600003C */  swc1      $f0, 0x3c($s0)
.L80240C9C:
/* 8ACC2C 80240C9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8ACC30 80240CA0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8ACC34 80240CA4 8FB00018 */  lw        $s0, 0x18($sp)
/* 8ACC38 80240CA8 03E00008 */  jr        $ra
/* 8ACC3C 80240CAC 27BD0028 */   addiu    $sp, $sp, 0x28
