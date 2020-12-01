.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContMgrRemove
/* 3B9E8 800605E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B9EC 800605EC 3C048009 */  lui       $a0, %hi(D_80093D38)
/* 3B9F0 800605F0 24843D38 */  addiu     $a0, $a0, %lo(D_80093D38)
/* 3B9F4 800605F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B9F8 800605F8 0C018124 */  jal       nuSiCallBackRemove
/* 3B9FC 800605FC 00000000 */   nop      
/* 3BA00 80060600 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BA04 80060604 03E00008 */  jr        $ra
/* 3BA08 80060608 27BD0018 */   addiu    $sp, $sp, 0x18
