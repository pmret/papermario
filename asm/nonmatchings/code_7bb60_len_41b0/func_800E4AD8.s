.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E4AD8
/* 7DF88 800E4AD8 3C038007 */  lui       $v1, 0x8007
/* 7DF8C 800E4ADC 8C637410 */  lw        $v1, 0x7410($v1)
/* 7DF90 800E4AE0 3C018011 */  lui       $at, 0x8011
/* 7DF94 800E4AE4 C422F070 */  lwc1      $f2, -0xf90($at)
/* 7DF98 800E4AE8 3C0142B4 */  lui       $at, 0x42b4
/* 7DF9C 800E4AEC 44810000 */  mtc1      $at, $f0
/* 7DFA0 800E4AF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7DFA4 800E4AF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7DFA8 800E4AF8 00031080 */  sll       $v0, $v1, 2
/* 7DFAC 800E4AFC 00431021 */  addu      $v0, $v0, $v1
/* 7DFB0 800E4B00 00021080 */  sll       $v0, $v0, 2
/* 7DFB4 800E4B04 00431023 */  subu      $v0, $v0, $v1
/* 7DFB8 800E4B08 000218C0 */  sll       $v1, $v0, 3
/* 7DFBC 800E4B0C 00431021 */  addu      $v0, $v0, $v1
/* 7DFC0 800E4B10 000210C0 */  sll       $v0, $v0, 3
/* 7DFC4 800E4B14 46001081 */  sub.s     $f2, $f2, $f0
/* 7DFC8 800E4B18 3C01800B */  lui       $at, 0x800b
/* 7DFCC 800E4B1C 00220821 */  addu      $at, $at, $v0
/* 7DFD0 800E4B20 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7DFD4 800E4B24 46001080 */  add.s     $f2, $f2, $f0
/* 7DFD8 800E4B28 44061000 */  mfc1      $a2, $f2
/* 7DFDC 800E4B2C 0C0390C2 */  jal       collision_check_player_intersecting_world
/* 7DFE0 800E4B30 0000282D */   daddu    $a1, $zero, $zero
/* 7DFE4 800E4B34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7DFE8 800E4B38 03E00008 */  jr        $ra
/* 7DFEC 800E4B3C 27BD0018 */   addiu    $sp, $sp, 0x18
