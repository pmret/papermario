.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800360B0
/* 114B0 800360B0 240200FF */  addiu     $v0, $zero, 0xff
/* 114B4 800360B4 3C01800A */  lui       $at, %hi(D_8009E750)
/* 114B8 800360B8 A422E750 */  sh        $v0, %lo(D_8009E750)($at)
/* 114BC 800360BC 24020014 */  addiu     $v0, $zero, 0x14
/* 114C0 800360C0 3C048011 */  lui       $a0, %hi(D_8010F188)
/* 114C4 800360C4 2484F188 */  addiu     $a0, $a0, %lo(D_8010F188)
/* 114C8 800360C8 3C01800A */  lui       $at, %hi(D_8009E752)
/* 114CC 800360CC A422E752 */  sh        $v0, %lo(D_8009E752)($at)
/* 114D0 800360D0 8C820000 */  lw        $v0, ($a0)
/* 114D4 800360D4 24030001 */  addiu     $v1, $zero, 1
/* 114D8 800360D8 3C01800A */  lui       $at, %hi(D_8009E754)
/* 114DC 800360DC A423E754 */  sh        $v1, %lo(D_8009E754)($at)
/* 114E0 800360E0 34421000 */  ori       $v0, $v0, 0x1000
/* 114E4 800360E4 03E00008 */  jr        $ra
/* 114E8 800360E8 AC820000 */   sw       $v0, ($a0)
