.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuScGetFrameRate
/* 3A39C 8005EF9C 3C02800E */  lui       $v0, 0x800e
/* 3A3A0 8005EFA0 03E00008 */  jr        $ra
/* 3A3A4 8005EFA4 9042AABC */   lbu      $v0, -0x5544($v0)
