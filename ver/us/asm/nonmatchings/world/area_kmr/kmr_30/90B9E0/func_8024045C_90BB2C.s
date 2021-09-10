.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024045C_90BB2C
/* 90BB2C 8024045C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 90BB30 80240460 AFBF0010 */  sw        $ra, 0x10($sp)
/* 90BB34 80240464 8C82000C */  lw        $v0, 0xc($a0)
/* 90BB38 80240468 0C0B1EAF */  jal       evt_get_variable
/* 90BB3C 8024046C 8C450000 */   lw       $a1, ($v0)
/* 90BB40 80240470 8FBF0010 */  lw        $ra, 0x10($sp)
/* 90BB44 80240474 3C018024 */  lui       $at, %hi(D_80240C0C_90C2DC)
/* 90BB48 80240478 AC220C0C */  sw        $v0, %lo(D_80240C0C_90C2DC)($at)
/* 90BB4C 8024047C 24020002 */  addiu     $v0, $zero, 2
/* 90BB50 80240480 03E00008 */  jr        $ra
/* 90BB54 80240484 27BD0018 */   addiu    $sp, $sp, 0x18
