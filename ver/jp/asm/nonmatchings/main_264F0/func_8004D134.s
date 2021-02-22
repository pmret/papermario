.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D134
/* 28534 8004D134 308200CC */  andi      $v0, $a0, 0xcc
/* 28538 8004D138 00021083 */  sra       $v0, $v0, 2
/* 2853C 8004D13C 30840013 */  andi      $a0, $a0, 0x13
/* 28540 8004D140 00042080 */  sll       $a0, $a0, 2
/* 28544 8004D144 00441021 */  addu      $v0, $v0, $a0
/* 28548 8004D148 00A20018 */  mult      $a1, $v0
/* 2854C 8004D14C 00001812 */  mflo      $v1
/* 28550 8004D150 34028000 */  ori       $v0, $zero, 0x8000
/* 28554 8004D154 00431023 */  subu      $v0, $v0, $v1
/* 28558 8004D158 00C20018 */  mult      $a2, $v0
/* 2855C 8004D15C 00001812 */  mflo      $v1
/* 28560 8004D160 000313C3 */  sra       $v0, $v1, 0xf
/* 28564 8004D164 03E00008 */  jr        $ra
/* 28568 8004D168 304200FF */   andi     $v0, $v0, 0xff
