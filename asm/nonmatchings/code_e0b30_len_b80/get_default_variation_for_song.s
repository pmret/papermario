.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_default_variation_for_song
/* E0B30 8014A430 0000302D */  daddu     $a2, $zero, $zero
/* E0B34 8014A434 3C078009 */  lui       $a3, 0x8009
/* E0B38 8014A438 24E734F0 */  addiu     $a3, $a3, 0x34f0
/* E0B3C 8014A43C 3C038007 */  lui       $v1, 0x8007
/* E0B40 8014A440 2463419C */  addiu     $v1, $v1, 0x419c
/* E0B44 8014A444 3C058015 */  lui       $a1, 0x8015
/* E0B48 8014A448 24A5F720 */  addiu     $a1, $a1, -0x8e0
.L8014A44C:
/* E0B4C 8014A44C 8CA20000 */  lw        $v0, ($a1)
/* E0B50 8014A450 1444000C */  bne       $v0, $a0, .L8014A484
/* E0B54 8014A454 24C60001 */   addiu    $a2, $a2, 1
/* E0B58 8014A458 8C630000 */  lw        $v1, ($v1)
/* E0B5C 8014A45C 84620086 */  lh        $v0, 0x86($v1)
/* E0B60 8014A460 8463008C */  lh        $v1, 0x8c($v1)
/* E0B64 8014A464 00021100 */  sll       $v0, $v0, 4
/* E0B68 8014A468 00471021 */  addu      $v0, $v0, $a3
/* E0B6C 8014A46C 8C420004 */  lw        $v0, 4($v0)
/* E0B70 8014A470 00031940 */  sll       $v1, $v1, 5
/* E0B74 8014A474 00431021 */  addu      $v0, $v0, $v1
/* E0B78 8014A478 9042001E */  lbu       $v0, 0x1e($v0)
/* E0B7C 8014A47C 03E00008 */  jr        $ra
/* E0B80 8014A480 30420001 */   andi     $v0, $v0, 1
.L8014A484:
/* E0B84 8014A484 2CC20006 */  sltiu     $v0, $a2, 6
/* E0B88 8014A488 1440FFF0 */  bnez      $v0, .L8014A44C
/* E0B8C 8014A48C 24A50004 */   addiu    $a1, $a1, 4
/* E0B90 8014A490 03E00008 */  jr        $ra
/* E0B94 8014A494 2402FFFF */   addiu    $v0, $zero, -1
