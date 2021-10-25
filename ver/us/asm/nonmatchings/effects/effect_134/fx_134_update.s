.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_134_update
/* 414CD0 E0128130 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 414CD4 E0128134 AFBF0010 */  sw        $ra, 0x10($sp)
/* 414CD8 E0128138 8C830000 */  lw        $v1, ($a0)
/* 414CDC E012813C 8C85000C */  lw        $a1, 0xc($a0)
/* 414CE0 E0128140 30620010 */  andi      $v0, $v1, 0x10
/* 414CE4 E0128144 10400005 */  beqz      $v0, .LE012815C
/* 414CE8 E0128148 2402FFEF */   addiu    $v0, $zero, -0x11
/* 414CEC E012814C 00621024 */  and       $v0, $v1, $v0
/* 414CF0 E0128150 AC820000 */  sw        $v0, ($a0)
/* 414CF4 E0128154 24020010 */  addiu     $v0, $zero, 0x10
/* 414CF8 E0128158 ACA20010 */  sw        $v0, 0x10($a1)
.LE012815C:
/* 414CFC E012815C 8CA30010 */  lw        $v1, 0x10($a1)
/* 414D00 E0128160 286203E8 */  slti      $v0, $v1, 0x3e8
/* 414D04 E0128164 10400002 */  beqz      $v0, .LE0128170
/* 414D08 E0128168 2462FFFF */   addiu    $v0, $v1, -1
/* 414D0C E012816C ACA20010 */  sw        $v0, 0x10($a1)
.LE0128170:
/* 414D10 E0128170 8CA20014 */  lw        $v0, 0x14($a1)
/* 414D14 E0128174 8CA30010 */  lw        $v1, 0x10($a1)
/* 414D18 E0128178 24420001 */  addiu     $v0, $v0, 1
/* 414D1C E012817C 04610003 */  bgez      $v1, .LE012818C
/* 414D20 E0128180 ACA20014 */   sw       $v0, 0x14($a1)
/* 414D24 E0128184 0C080128 */  jal       shim_remove_effect
/* 414D28 E0128188 00000000 */   nop
.LE012818C:
/* 414D2C E012818C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 414D30 E0128190 03E00008 */  jr        $ra
/* 414D34 E0128194 27BD0018 */   addiu    $sp, $sp, 0x18
