.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001449C
/* 32E92C E001449C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32E930 E00144A0 3C02E001 */  lui       $v0, %hi(D_E00144E0)
/* 32E934 E00144A4 244244E0 */  addiu     $v0, $v0, %lo(D_E00144E0)
/* 32E938 E00144A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32E93C E00144AC 24020028 */  addiu     $v0, $zero, 0x28
/* 32E940 E00144B0 AFA40018 */  sw        $a0, 0x18($sp)
/* 32E944 E00144B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 32E948 E00144B8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 32E94C E00144BC AFA00014 */  sw        $zero, 0x14($sp)
/* 32E950 E00144C0 0C080120 */  jal       func_E0200480
/* 32E954 E00144C4 AFA20010 */   sw       $v0, 0x10($sp)
/* 32E958 E00144C8 8C430000 */  lw        $v1, ($v0)
/* 32E95C E00144CC 34630002 */  ori       $v1, $v1, 2
/* 32E960 E00144D0 AC430000 */  sw        $v1, ($v0)
/* 32E964 E00144D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 32E968 E00144D8 03E00008 */  jr        $ra
/* 32E96C E00144DC 27BD0028 */   addiu    $sp, $sp, 0x28
