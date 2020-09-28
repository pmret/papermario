.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053AEC
/* 2EEEC 80053AEC 00051400 */  sll       $v0, $a1, 0x10
/* 2EEF0 80053AF0 AC820010 */  sw        $v0, 0x10($a0)
/* 2EEF4 80053AF4 A4850018 */  sh        $a1, 0x18($a0)
/* 2EEF8 80053AF8 A480001A */  sh        $zero, 0x1a($a0)
/* 2EEFC 80053AFC 03E00008 */  jr        $ra
/* 2EF00 80053B00 AC800014 */   sw       $zero, 0x14($a0)
