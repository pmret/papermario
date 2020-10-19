.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242934_C883E4
/* C883E4 80242934 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C883E8 80242938 AFBF0010 */  sw        $ra, 0x10($sp)
/* C883EC 8024293C 8C82000C */  lw        $v0, 0xc($a0)
/* C883F0 80242940 0C0B1EAF */  jal       get_variable
/* C883F4 80242944 8C450000 */   lw       $a1, ($v0)
/* C883F8 80242948 3C018024 */  lui       $at, 0x8024
/* C883FC 8024294C AC2240DC */  sw        $v0, 0x40dc($at)
/* C88400 80242950 24020002 */  addiu     $v0, $zero, 2
/* C88404 80242954 8FBF0010 */  lw        $ra, 0x10($sp)
/* C88408 80242958 24030001 */  addiu     $v1, $zero, 1
/* C8840C 8024295C 3C018024 */  lui       $at, 0x8024
/* C88410 80242960 AC2340D8 */  sw        $v1, 0x40d8($at)
/* C88414 80242964 03E00008 */  jr        $ra
/* C88418 80242968 27BD0018 */   addiu    $sp, $sp, 0x18
