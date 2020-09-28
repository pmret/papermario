.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FD38
/* 2B138 8004FD38 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B13C 8004FD3C 00823821 */  addu      $a3, $a0, $v0
/* 2B140 8004FD40 2C420004 */  sltiu     $v0, $v0, 4
/* 2B144 8004FD44 90E3004C */  lbu       $v1, 0x4c($a3)
/* 2B148 8004FD48 10400010 */  beqz      $v0, .L8004FD8C
/* 2B14C 8004FD4C 2C620080 */   sltiu    $v0, $v1, 0x80
/* 2B150 8004FD50 1040000E */  beqz      $v0, .L8004FD8C
/* 2B154 8004FD54 00033080 */   sll      $a2, $v1, 2
/* 2B158 8004FD58 8C820000 */  lw        $v0, ($a0)
/* 2B15C 8004FD5C 908300D5 */  lbu       $v1, 0xd5($a0)
/* 2B160 8004FD60 00462821 */  addu      $a1, $v0, $a2
/* 2B164 8004FD64 90A20040 */  lbu       $v0, 0x40($a1)
/* 2B168 8004FD68 10430006 */  beq       $v0, $v1, .L8004FD84
/* 2B16C 8004FD6C 00000000 */   nop      
/* 2B170 8004FD70 A0A30040 */  sb        $v1, 0x40($a1)
/* 2B174 8004FD74 8C820000 */  lw        $v0, ($a0)
/* 2B178 8004FD78 24030001 */  addiu     $v1, $zero, 1
/* 2B17C 8004FD7C 00461021 */  addu      $v0, $v0, $a2
/* 2B180 8004FD80 A0430041 */  sb        $v1, 0x41($v0)
.L8004FD84:
/* 2B184 8004FD84 908200D5 */  lbu       $v0, 0xd5($a0)
/* 2B188 8004FD88 A0E20224 */  sb        $v0, 0x224($a3)
.L8004FD8C:
/* 2B18C 8004FD8C 03E00008 */  jr        $ra
/* 2B190 8004FD90 00000000 */   nop      
