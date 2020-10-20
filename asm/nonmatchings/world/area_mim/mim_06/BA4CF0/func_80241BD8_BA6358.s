.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BD8_BA6358
/* BA6358 80241BD8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BA635C 80241BDC AFB40040 */  sw        $s4, 0x40($sp)
/* BA6360 80241BE0 0080A02D */  daddu     $s4, $a0, $zero
/* BA6364 80241BE4 AFBF0044 */  sw        $ra, 0x44($sp)
/* BA6368 80241BE8 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA636C 80241BEC AFB20038 */  sw        $s2, 0x38($sp)
/* BA6370 80241BF0 AFB10034 */  sw        $s1, 0x34($sp)
/* BA6374 80241BF4 AFB00030 */  sw        $s0, 0x30($sp)
/* BA6378 80241BF8 8E910148 */  lw        $s1, 0x148($s4)
/* BA637C 80241BFC 00A0902D */  daddu     $s2, $a1, $zero
/* BA6380 80241C00 86240008 */  lh        $a0, 8($s1)
/* BA6384 80241C04 0C00EABB */  jal       get_npc_unsafe
/* BA6388 80241C08 00C0982D */   daddu    $s3, $a2, $zero
/* BA638C 80241C0C 0040802D */  daddu     $s0, $v0, $zero
/* BA6390 80241C10 9602008E */  lhu       $v0, 0x8e($s0)
/* BA6394 80241C14 2442FFFF */  addiu     $v0, $v0, -1
/* BA6398 80241C18 A602008E */  sh        $v0, 0x8e($s0)
/* BA639C 80241C1C 00021400 */  sll       $v0, $v0, 0x10
/* BA63A0 80241C20 14400020 */  bnez      $v0, .L80241CA4
/* BA63A4 80241C24 0260202D */   daddu    $a0, $s3, $zero
/* BA63A8 80241C28 AFA00010 */  sw        $zero, 0x10($sp)
/* BA63AC 80241C2C 8E46000C */  lw        $a2, 0xc($s2)
/* BA63B0 80241C30 8E470010 */  lw        $a3, 0x10($s2)
/* BA63B4 80241C34 0C01242D */  jal       func_800490B4
/* BA63B8 80241C38 0220282D */   daddu    $a1, $s1, $zero
/* BA63BC 80241C3C 54400018 */  bnel      $v0, $zero, .L80241CA0
/* BA63C0 80241C40 A600008E */   sh       $zero, 0x8e($s0)
/* BA63C4 80241C44 24040002 */  addiu     $a0, $zero, 2
/* BA63C8 80241C48 0200282D */  daddu     $a1, $s0, $zero
/* BA63CC 80241C4C 0000302D */  daddu     $a2, $zero, $zero
/* BA63D0 80241C50 860300A8 */  lh        $v1, 0xa8($s0)
/* BA63D4 80241C54 3C013F80 */  lui       $at, 0x3f80
/* BA63D8 80241C58 44810000 */  mtc1      $at, $f0
/* BA63DC 80241C5C 3C014000 */  lui       $at, 0x4000
/* BA63E0 80241C60 44811000 */  mtc1      $at, $f2
/* BA63E4 80241C64 3C01C1A0 */  lui       $at, 0xc1a0
/* BA63E8 80241C68 44812000 */  mtc1      $at, $f4
/* BA63EC 80241C6C 2402000F */  addiu     $v0, $zero, 0xf
/* BA63F0 80241C70 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA63F4 80241C74 44833000 */  mtc1      $v1, $f6
/* BA63F8 80241C78 00000000 */  nop       
/* BA63FC 80241C7C 468031A0 */  cvt.s.w   $f6, $f6
/* BA6400 80241C80 44073000 */  mfc1      $a3, $f6
/* BA6404 80241C84 27A20028 */  addiu     $v0, $sp, 0x28
/* BA6408 80241C88 AFA20020 */  sw        $v0, 0x20($sp)
/* BA640C 80241C8C E7A00010 */  swc1      $f0, 0x10($sp)
/* BA6410 80241C90 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA6414 80241C94 0C01BFA4 */  jal       fx_emote
/* BA6418 80241C98 E7A40018 */   swc1     $f4, 0x18($sp)
/* BA641C 80241C9C A600008E */  sh        $zero, 0x8e($s0)
.L80241CA0:
/* BA6420 80241CA0 AE800070 */  sw        $zero, 0x70($s4)
.L80241CA4:
/* BA6424 80241CA4 8FBF0044 */  lw        $ra, 0x44($sp)
/* BA6428 80241CA8 8FB40040 */  lw        $s4, 0x40($sp)
/* BA642C 80241CAC 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA6430 80241CB0 8FB20038 */  lw        $s2, 0x38($sp)
/* BA6434 80241CB4 8FB10034 */  lw        $s1, 0x34($sp)
/* BA6438 80241CB8 8FB00030 */  lw        $s0, 0x30($sp)
/* BA643C 80241CBC 03E00008 */  jr        $ra
/* BA6440 80241CC0 27BD0048 */   addiu    $sp, $sp, 0x48
