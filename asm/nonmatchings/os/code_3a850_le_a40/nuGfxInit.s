.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxInit
/* 3A960 8005F560 27BDF7E8 */  addiu     $sp, $sp, -0x818
/* 3A964 8005F564 AFBF0810 */  sw        $ra, 0x810($sp)
/* 3A968 8005F568 0C01807C */  jal       nuGfxThreadStart
/* 3A96C 8005F56C 00000000 */   nop      
/* 3A970 8005F570 3C048009 */  lui       $a0, 0x8009
/* 3A974 8005F574 24843BA8 */  addiu     $a0, $a0, 0x3ba8
/* 3A978 8005F578 0C017CBC */  jal       nuGfxSetCfb
/* 3A97C 8005F57C 24050003 */   addiu    $a1, $zero, 3
/* 3A980 8005F580 3C028000 */  lui       $v0, 0x8000
/* 3A984 8005F584 34420400 */  ori       $v0, $v0, 0x400
/* 3A988 8005F588 3C048006 */  lui       $a0, 0x8006
/* 3A98C 8005F58C 24840350 */  addiu     $a0, $a0, 0x350
/* 3A990 8005F590 3C01800A */  lui       $at, 0x800a
/* 3A994 8005F594 AC22A5DC */  sw        $v0, -0x5a24($at)
/* 3A998 8005F598 0C0180C4 */  jal       nuGfxSwapCfbFuncSet
/* 3A99C 8005F59C 00000000 */   nop      
/* 3A9A0 8005F5A0 3C028009 */  lui       $v0, 0x8009
/* 3A9A4 8005F5A4 24423BA0 */  addiu     $v0, $v0, 0x3ba0
/* 3A9A8 8005F5A8 3C01800A */  lui       $at, 0x800a
/* 3A9AC 8005F5AC AC22A610 */  sw        $v0, -0x59f0($at)
/* 3A9B0 8005F5B0 0C00B2CE */  jal       nuGfxTaskMgrInit
/* 3A9B4 8005F5B4 00000000 */   nop      
/* 3A9B8 8005F5B8 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A9BC 8005F5BC 27A50028 */  addiu     $a1, $sp, 0x28
/* 3A9C0 8005F5C0 00A42823 */  subu      $a1, $a1, $a0
/* 3A9C4 8005F5C4 3C02DE00 */  lui       $v0, 0xde00
/* 3A9C8 8005F5C8 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A9CC 8005F5CC 3C020009 */  lui       $v0, 9
/* 3A9D0 8005F5D0 24423BB8 */  addiu     $v0, $v0, 0x3bb8
/* 3A9D4 8005F5D4 AC820004 */  sw        $v0, 4($a0)
/* 3A9D8 8005F5D8 3C02E900 */  lui       $v0, 0xe900
/* 3A9DC 8005F5DC AFA20018 */  sw        $v0, 0x18($sp)
/* 3A9E0 8005F5E0 3C02DF00 */  lui       $v0, 0xdf00
/* 3A9E4 8005F5E4 0000302D */  daddu     $a2, $zero, $zero
/* 3A9E8 8005F5E8 00C0382D */  daddu     $a3, $a2, $zero
/* 3A9EC 8005F5EC AFA0001C */  sw        $zero, 0x1c($sp)
/* 3A9F0 8005F5F0 AFA20020 */  sw        $v0, 0x20($sp)
/* 3A9F4 8005F5F4 0C00B331 */  jal       nuGfxTaskStart
/* 3A9F8 8005F5F8 AFA00024 */   sw       $zero, 0x24($sp)
/* 3A9FC 8005F5FC 0C017CB4 */  jal       nuGfxTaskAllEndWait
/* 3AA00 8005F600 00000000 */   nop      
/* 3AA04 8005F604 8FBF0810 */  lw        $ra, 0x810($sp)
/* 3AA08 8005F608 03E00008 */  jr        $ra
/* 3AA0C 8005F60C 27BD0818 */   addiu    $sp, $sp, 0x818
