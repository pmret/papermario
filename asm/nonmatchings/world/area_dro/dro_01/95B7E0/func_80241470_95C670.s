.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241470_95C670
/* 95C670 80241470 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95C674 80241474 AFB00010 */  sw        $s0, 0x10($sp)
/* 95C678 80241478 3C108024 */  lui       $s0, %hi(D_802451B8_9603B8)
/* 95C67C 8024147C 261051B8 */  addiu     $s0, $s0, %lo(D_802451B8_9603B8)
/* 95C680 80241480 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95C684 80241484 AFB10014 */  sw        $s1, 0x14($sp)
/* 95C688 80241488 8E020000 */  lw        $v0, ($s0)
/* 95C68C 8024148C 14400010 */  bnez      $v0, .L802414D0
/* 95C690 80241490 0080882D */   daddu    $s1, $a0, $zero
/* 95C694 80241494 0C00AB39 */  jal       heap_malloc
/* 95C698 80241498 24040040 */   addiu    $a0, $zero, 0x40
/* 95C69C 8024149C AE020000 */  sw        $v0, ($s0)
/* 95C6A0 802414A0 0000182D */  daddu     $v1, $zero, $zero
/* 95C6A4 802414A4 0040282D */  daddu     $a1, $v0, $zero
/* 95C6A8 802414A8 0220202D */  daddu     $a0, $s1, $zero
.L802414AC:
/* 95C6AC 802414AC 8C820084 */  lw        $v0, 0x84($a0)
/* 95C6B0 802414B0 24840004 */  addiu     $a0, $a0, 4
/* 95C6B4 802414B4 24630001 */  addiu     $v1, $v1, 1
/* 95C6B8 802414B8 ACA20000 */  sw        $v0, ($a1)
/* 95C6BC 802414BC 28620010 */  slti      $v0, $v1, 0x10
/* 95C6C0 802414C0 1440FFFA */  bnez      $v0, .L802414AC
/* 95C6C4 802414C4 24A50004 */   addiu    $a1, $a1, 4
/* 95C6C8 802414C8 08090543 */  j         .L8024150C
/* 95C6CC 802414CC 00000000 */   nop
.L802414D0:
/* 95C6D0 802414D0 0000182D */  daddu     $v1, $zero, $zero
/* 95C6D4 802414D4 0040282D */  daddu     $a1, $v0, $zero
/* 95C6D8 802414D8 0220202D */  daddu     $a0, $s1, $zero
.L802414DC:
/* 95C6DC 802414DC 8CA20000 */  lw        $v0, ($a1)
/* 95C6E0 802414E0 24A50004 */  addiu     $a1, $a1, 4
/* 95C6E4 802414E4 24630001 */  addiu     $v1, $v1, 1
/* 95C6E8 802414E8 AC820084 */  sw        $v0, 0x84($a0)
/* 95C6EC 802414EC 28620010 */  slti      $v0, $v1, 0x10
/* 95C6F0 802414F0 1440FFFA */  bnez      $v0, .L802414DC
/* 95C6F4 802414F4 24840004 */   addiu    $a0, $a0, 4
/* 95C6F8 802414F8 3C108024 */  lui       $s0, %hi(D_802451B8_9603B8)
/* 95C6FC 802414FC 261051B8 */  addiu     $s0, $s0, %lo(D_802451B8_9603B8)
/* 95C700 80241500 0C00AB4B */  jal       heap_free
/* 95C704 80241504 8E040000 */   lw       $a0, ($s0)
/* 95C708 80241508 AE000000 */  sw        $zero, ($s0)
.L8024150C:
/* 95C70C 8024150C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95C710 80241510 8FB10014 */  lw        $s1, 0x14($sp)
/* 95C714 80241514 8FB00010 */  lw        $s0, 0x10($sp)
/* 95C718 80241518 24020002 */  addiu     $v0, $zero, 2
/* 95C71C 8024151C 03E00008 */  jr        $ra
/* 95C720 80241520 27BD0020 */   addiu    $sp, $sp, 0x20
