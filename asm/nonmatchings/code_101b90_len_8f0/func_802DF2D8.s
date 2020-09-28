.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DF2D8
/* 1023C8 802DF2D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1023CC 802DF2DC AFB00010 */  sw        $s0, 0x10($sp)
/* 1023D0 802DF2E0 0080802D */  daddu     $s0, $a0, $zero
/* 1023D4 802DF2E4 26020001 */  addiu     $v0, $s0, 1
/* 1023D8 802DF2E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1023DC 802DF2EC 00028880 */  sll       $s1, $v0, 2
/* 1023E0 802DF2F0 00101080 */  sll       $v0, $s0, 2
/* 1023E4 802DF2F4 00501021 */  addu      $v0, $v0, $s0
/* 1023E8 802DF2F8 00021100 */  sll       $v0, $v0, 4
/* 1023EC 802DF2FC 3C03802E */  lui       $v1, 0x802e
/* 1023F0 802DF300 8C63F524 */  lw        $v1, -0xadc($v1)
/* 1023F4 802DF304 00512821 */  addu      $a1, $v0, $s1
/* 1023F8 802DF308 3C048035 */  lui       $a0, 0x8035
/* 1023FC 802DF30C 2484F800 */  addiu     $a0, $a0, -0x800
/* 102400 802DF310 10600003 */  beqz      $v1, .L802DF320
/* 102404 802DF314 AFBF0018 */   sw       $ra, 0x18($sp)
/* 102408 802DF318 3C048030 */  lui       $a0, %hi(D_802FB800)
/* 10240C 802DF31C 2484B800 */  addiu     $a0, $a0, %lo(D_802FB800)
.L802DF320:
/* 102410 802DF320 0C00A41B */  jal       _heap_malloc
/* 102414 802DF324 00000000 */   nop      
/* 102418 802DF328 0040302D */  daddu     $a2, $v0, $zero
/* 10241C 802DF32C 00C0282D */  daddu     $a1, $a2, $zero
/* 102420 802DF330 0220102D */  daddu     $v0, $s1, $zero
/* 102424 802DF334 04410002 */  bgez      $v0, .L802DF340
/* 102428 802DF338 00C0202D */   daddu    $a0, $a2, $zero
/* 10242C 802DF33C 24420003 */  addiu     $v0, $v0, 3
.L802DF340:
/* 102430 802DF340 00021083 */  sra       $v0, $v0, 2
/* 102434 802DF344 00021080 */  sll       $v0, $v0, 2
/* 102438 802DF348 00822021 */  addu      $a0, $a0, $v0
/* 10243C 802DF34C 1A000007 */  blez      $s0, .L802DF36C
/* 102440 802DF350 0000182D */   daddu    $v1, $zero, $zero
.L802DF354:
/* 102444 802DF354 ACA40000 */  sw        $a0, ($a1)
/* 102448 802DF358 24A50004 */  addiu     $a1, $a1, 4
/* 10244C 802DF35C 24630001 */  addiu     $v1, $v1, 1
/* 102450 802DF360 0070102A */  slt       $v0, $v1, $s0
/* 102454 802DF364 1440FFFB */  bnez      $v0, .L802DF354
/* 102458 802DF368 24840050 */   addiu    $a0, $a0, 0x50
.L802DF36C:
/* 10245C 802DF36C 2402FFFF */  addiu     $v0, $zero, -1
/* 102460 802DF370 ACA20000 */  sw        $v0, ($a1)
/* 102464 802DF374 8FBF0018 */  lw        $ra, 0x18($sp)
/* 102468 802DF378 8FB10014 */  lw        $s1, 0x14($sp)
/* 10246C 802DF37C 8FB00010 */  lw        $s0, 0x10($sp)
/* 102470 802DF380 00C0102D */  daddu     $v0, $a2, $zero
/* 102474 802DF384 03E00008 */  jr        $ra
/* 102478 802DF388 27BD0020 */   addiu    $sp, $sp, 0x20
/* 10247C 802DF38C 00000000 */  nop       
