.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD144
/* 31B164 802BD144 3C038011 */  lui       $v1, 0x8011
/* 31B168 802BD148 8C63C978 */  lw        $v1, -0x3688($v1)
/* 31B16C 802BD14C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31B170 802BD150 04600007 */  bltz      $v1, .L802BD170
/* 31B174 802BD154 AFBF0010 */   sw       $ra, 0x10($sp)
/* 31B178 802BD158 30624000 */  andi      $v0, $v1, 0x4000
/* 31B17C 802BD15C 10400004 */  beqz      $v0, .L802BD170
/* 31B180 802BD160 00000000 */   nop      
/* 31B184 802BD164 2404BFFF */  addiu     $a0, $zero, -0x4001
/* 31B188 802BD168 0C044277 */  jal       func_801109DC
/* 31B18C 802BD16C 00642024 */   and      $a0, $v1, $a0
.L802BD170:
/* 31B190 802BD170 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31B194 802BD174 03E00008 */  jr        $ra
/* 31B198 802BD178 27BD0018 */   addiu    $sp, $sp, 0x18
