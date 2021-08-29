.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026ED20
/* 19D600 8026ED20 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19D604 8026ED24 AFB20018 */  sw        $s2, 0x18($sp)
/* 19D608 8026ED28 0080902D */  daddu     $s2, $a0, $zero
/* 19D60C 8026ED2C AFBF0020 */  sw        $ra, 0x20($sp)
/* 19D610 8026ED30 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19D614 8026ED34 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D618 8026ED38 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D61C 8026ED3C 8E50000C */  lw        $s0, 0xc($s2)
/* 19D620 8026ED40 8E050000 */  lw        $a1, ($s0)
/* 19D624 8026ED44 0C0B1EAF */  jal       evt_get_variable
/* 19D628 8026ED48 26100004 */   addiu    $s0, $s0, 4
/* 19D62C 8026ED4C 0040882D */  daddu     $s1, $v0, $zero
/* 19D630 8026ED50 8E050000 */  lw        $a1, ($s0)
/* 19D634 8026ED54 26100004 */  addiu     $s0, $s0, 4
/* 19D638 8026ED58 0C0B1EAF */  jal       evt_get_variable
/* 19D63C 8026ED5C 0240202D */   daddu    $a0, $s2, $zero
/* 19D640 8026ED60 0240202D */  daddu     $a0, $s2, $zero
/* 19D644 8026ED64 8E050000 */  lw        $a1, ($s0)
/* 19D648 8026ED68 0C0B1EAF */  jal       evt_get_variable
/* 19D64C 8026ED6C 0040802D */   daddu    $s0, $v0, $zero
/* 19D650 8026ED70 0040982D */  daddu     $s3, $v0, $zero
/* 19D654 8026ED74 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D658 8026ED78 16220002 */  bne       $s1, $v0, .L8026ED84
/* 19D65C 8026ED7C 00000000 */   nop
/* 19D660 8026ED80 8E510148 */  lw        $s1, 0x148($s2)
.L8026ED84:
/* 19D664 8026ED84 0C09A75B */  jal       get_actor
/* 19D668 8026ED88 0220202D */   daddu    $a0, $s1, $zero
/* 19D66C 8026ED8C 0040202D */  daddu     $a0, $v0, $zero
/* 19D670 8026ED90 0C099117 */  jal       get_actor_part
/* 19D674 8026ED94 0200282D */   daddu    $a1, $s0, $zero
/* 19D678 8026ED98 12600005 */  beqz      $s3, .L8026EDB0
/* 19D67C 8026ED9C 0040202D */   daddu    $a0, $v0, $zero
/* 19D680 8026EDA0 8C820000 */  lw        $v0, ($a0)
/* 19D684 8026EDA4 3C030100 */  lui       $v1, 0x100
/* 19D688 8026EDA8 0809BB70 */  j         .L8026EDC0
/* 19D68C 8026EDAC 00431025 */   or       $v0, $v0, $v1
.L8026EDB0:
/* 19D690 8026EDB0 3C03FEFF */  lui       $v1, 0xfeff
/* 19D694 8026EDB4 8C820000 */  lw        $v0, ($a0)
/* 19D698 8026EDB8 3463FFFF */  ori       $v1, $v1, 0xffff
/* 19D69C 8026EDBC 00431024 */  and       $v0, $v0, $v1
.L8026EDC0:
/* 19D6A0 8026EDC0 AC820000 */  sw        $v0, ($a0)
/* 19D6A4 8026EDC4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19D6A8 8026EDC8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D6AC 8026EDCC 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D6B0 8026EDD0 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D6B4 8026EDD4 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D6B8 8026EDD8 24020002 */  addiu     $v0, $zero, 2
/* 19D6BC 8026EDDC 03E00008 */  jr        $ra
/* 19D6C0 8026EDE0 27BD0028 */   addiu    $sp, $sp, 0x28
