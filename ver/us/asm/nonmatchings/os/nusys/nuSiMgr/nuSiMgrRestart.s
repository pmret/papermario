.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuSiMgrRestart
/* 83AC 8002CFAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 83B0 8002CFB0 3C04800A */  lui       $a0, %hi(D_8009E710)
/* 83B4 8002CFB4 2484E710 */  addiu     $a0, $a0, %lo(D_8009E710)
/* 83B8 8002CFB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 83BC 8002CFBC 0C019808 */  jal       osStartThread
/* 83C0 8002CFC0 00000000 */   nop
/* 83C4 8002CFC4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 83C8 8002CFC8 03E00008 */  jr        $ra
/* 83CC 8002CFCC 27BD0018 */   addiu    $sp, $sp, 0x18
