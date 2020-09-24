.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetBattleOutcome
/* 1F97C 8004457C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F980 80044580 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F984 80044584 8C82000C */  lw        $v0, 0xc($a0)
/* 1F988 80044588 3C06800B */  lui       $a2, 0x800b
/* 1F98C 8004458C 80C60F19 */  lb        $a2, 0xf19($a2)
/* 1F990 80044590 0C0B2026 */  jal       set_variable
/* 1F994 80044594 8C450000 */   lw       $a1, ($v0)
/* 1F998 80044598 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F99C 8004459C 24020002 */  addiu     $v0, $zero, 2
/* 1F9A0 800445A0 03E00008 */  jr        $ra
/* 1F9A4 800445A4 27BD0018 */   addiu    $sp, $sp, 0x18
