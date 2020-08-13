.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetActionSuccessCopy
/* 197DD8 802694F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197DDC 802694FC AFBF0010 */  sw    $ra, 0x10($sp)
/* 197DE0 80269500 8C82000C */  lw    $v0, 0xc($a0)
/* 197DE4 80269504 3C06800E */  lui   $a2, 0x800e
/* 197DE8 80269508 80C6C0F1 */  lb    $a2, -0x3f0f($a2)
/* 197DEC 8026950C 0C0B2026 */  jal   set_variable
/* 197DF0 80269510 8C450000 */   lw    $a1, ($v0)
/* 197DF4 80269514 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197DF8 80269518 24020002 */  addiu $v0, $zero, 2
/* 197DFC 8026951C 03E00008 */  jr    $ra
/* 197E00 80269520 27BD0018 */   addiu $sp, $sp, 0x18

/* 197E04 80269524 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197E08 80269528 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197E0C 8026952C 8C82000C */  lw    $v0, 0xc($a0)
/* 197E10 80269530 3C06800E */  lui   $a2, 0x800e
/* 197E14 80269534 80C6C0F6 */  lb    $a2, -0x3f0a($a2)
/* 197E18 80269538 0C0B2026 */  jal   set_variable
/* 197E1C 8026953C 8C450000 */   lw    $a1, ($v0)
/* 197E20 80269540 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197E24 80269544 24020002 */  addiu $v0, $zero, 2
/* 197E28 80269548 03E00008 */  jr    $ra
/* 197E2C 8026954C 27BD0018 */   addiu $sp, $sp, 0x18

/* 197E30 80269550 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197E34 80269554 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197E38 80269558 8C82000C */  lw    $v0, 0xc($a0)
/* 197E3C 8026955C 0C0B1EAF */  jal   get_variable
/* 197E40 80269560 8C450000 */   lw    $a1, ($v0)
/* 197E44 80269564 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197E48 80269568 3C01800E */  lui   $at, 0x800e
/* 197E4C 8026956C A022C0F6 */  sb    $v0, -0x3f0a($at)
/* 197E50 80269570 24020002 */  addiu $v0, $zero, 2
/* 197E54 80269574 03E00008 */  jr    $ra
/* 197E58 80269578 27BD0018 */   addiu $sp, $sp, 0x18

