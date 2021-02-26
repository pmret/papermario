.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F3F8
/* 3A7F8 8005F3F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A7FC 8005F3FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A800 8005F400 8C85000C */  lw        $a1, 0xc($a0)
/* 3A804 8005F404 8CA20000 */  lw        $v0, ($a1)
/* 3A808 8005F408 8C440000 */  lw        $a0, ($v0)
/* 3A80C 8005F40C 0C01A3D8 */  jal       func_80068F60
/* 3A810 8005F410 24A50004 */   addiu    $a1, $a1, 4
/* 3A814 8005F414 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A818 8005F418 03E00008 */  jr        $ra
/* 3A81C 8005F41C 27BD0018 */   addiu    $sp, $sp, 0x18
