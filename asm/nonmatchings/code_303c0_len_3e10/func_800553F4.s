.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800553F4
/* 307F4 800553F4 3C03800A */  lui       $v1, %hi(D_8009A640)
/* 307F8 800553F8 8C63A640 */  lw        $v1, %lo(D_8009A640)($v1)
/* 307FC 800553FC 24020001 */  addiu     $v0, $zero, 1
/* 30800 80055400 03E00008 */  jr        $ra
/* 30804 80055404 AC620168 */   sw       $v0, 0x168($v1)
