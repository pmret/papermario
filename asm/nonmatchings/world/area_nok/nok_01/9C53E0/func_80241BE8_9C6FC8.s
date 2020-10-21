.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BE8_9C6FC8
/* 9C6FC8 80241BE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C6FCC 80241BEC AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6FD0 80241BF0 0080882D */  daddu     $s1, $a0, $zero
/* 9C6FD4 80241BF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6FD8 80241BF8 00A0802D */  daddu     $s0, $a1, $zero
/* 9C6FDC 80241BFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C6FE0 80241C00 0C00EABB */  jal       get_npc_unsafe
/* 9C6FE4 80241C04 2404FFFC */   addiu    $a0, $zero, -4
/* 9C6FE8 80241C08 12000003 */  beqz      $s0, .L80241C18
/* 9C6FEC 80241C0C 0040182D */   daddu    $v1, $v0, $zero
/* 9C6FF0 80241C10 2402003C */  addiu     $v0, $zero, 0x3c
/* 9C6FF4 80241C14 AE220070 */  sw        $v0, 0x70($s1)
.L80241C18:
/* 9C6FF8 80241C18 C462000C */  lwc1      $f2, 0xc($v1)
/* 9C6FFC 80241C1C 3C0141F0 */  lui       $at, 0x41f0
/* 9C7000 80241C20 44810000 */  mtc1      $at, $f0
/* 9C7004 80241C24 00000000 */  nop       
/* 9C7008 80241C28 46001000 */  add.s     $f0, $f2, $f0
/* 9C700C 80241C2C 3C0143B4 */  lui       $at, 0x43b4
/* 9C7010 80241C30 44811000 */  mtc1      $at, $f2
/* 9C7014 80241C34 00000000 */  nop       
/* 9C7018 80241C38 4600103E */  c.le.s    $f2, $f0
/* 9C701C 80241C3C 00000000 */  nop       
/* 9C7020 80241C40 45000003 */  bc1f      .L80241C50
/* 9C7024 80241C44 E460000C */   swc1     $f0, 0xc($v1)
/* 9C7028 80241C48 46020001 */  sub.s     $f0, $f0, $f2
/* 9C702C 80241C4C E460000C */  swc1      $f0, 0xc($v1)
.L80241C50:
/* 9C7030 80241C50 8E230070 */  lw        $v1, 0x70($s1)
/* 9C7034 80241C54 2463FFFF */  addiu     $v1, $v1, -1
/* 9C7038 80241C58 000317C3 */  sra       $v0, $v1, 0x1f
/* 9C703C 80241C5C AE230070 */  sw        $v1, 0x70($s1)
/* 9C7040 80241C60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C7044 80241C64 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C7048 80241C68 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C704C 80241C6C 30420002 */  andi      $v0, $v0, 2
/* 9C7050 80241C70 03E00008 */  jr        $ra
/* 9C7054 80241C74 27BD0020 */   addiu    $sp, $sp, 0x20
