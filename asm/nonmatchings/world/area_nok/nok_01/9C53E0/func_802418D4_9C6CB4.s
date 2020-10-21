.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418D4_9C6CB4
/* 9C6CB4 802418D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C6CB8 802418D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6CBC 802418DC 0080882D */  daddu     $s1, $a0, $zero
/* 9C6CC0 802418E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C6CC4 802418E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6CC8 802418E8 8E30000C */  lw        $s0, 0xc($s1)
/* 9C6CCC 802418EC 8E050000 */  lw        $a1, ($s0)
/* 9C6CD0 802418F0 0C0B1EAF */  jal       get_variable
/* 9C6CD4 802418F4 26100004 */   addiu    $s0, $s0, 4
/* 9C6CD8 802418F8 0220202D */  daddu     $a0, $s1, $zero
/* 9C6CDC 802418FC 8E050000 */  lw        $a1, ($s0)
/* 9C6CE0 80241900 0C0B210B */  jal       get_float_variable
/* 9C6CE4 80241904 0040802D */   daddu    $s0, $v0, $zero
/* 9C6CE8 80241908 24020002 */  addiu     $v0, $zero, 2
/* 9C6CEC 8024190C 00501804 */  sllv      $v1, $s0, $v0
/* 9C6CF0 80241910 00701821 */  addu      $v1, $v1, $s0
/* 9C6CF4 80241914 00431804 */  sllv      $v1, $v1, $v0
/* 9C6CF8 80241918 00701823 */  subu      $v1, $v1, $s0
/* 9C6CFC 8024191C 000320C0 */  sll       $a0, $v1, 3
/* 9C6D00 80241920 00641821 */  addu      $v1, $v1, $a0
/* 9C6D04 80241924 000318C0 */  sll       $v1, $v1, 3
/* 9C6D08 80241928 3C01800B */  lui       $at, 0x800b
/* 9C6D0C 8024192C 00230821 */  addu      $at, $at, $v1
/* 9C6D10 80241930 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 9C6D14 80241934 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C6D18 80241938 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C6D1C 8024193C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C6D20 80241940 03E00008 */  jr        $ra
/* 9C6D24 80241944 27BD0020 */   addiu    $sp, $sp, 0x20
