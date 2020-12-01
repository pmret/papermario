.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802AA640
/* 41F3D0 802AA640 3C02800E */  lui       $v0, %hi(gBattleStatus+0x46C)
/* 41F3D4 802AA644 8C42C4DC */  lw        $v0, %lo(gBattleStatus+0x46C)($v0)
/* 41F3D8 802AA648 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41F3DC 802AA64C 2443FFFF */  addiu     $v1, $v0, -1
/* 41F3E0 802AA650 2C620009 */  sltiu     $v0, $v1, 9
/* 41F3E4 802AA654 10400009 */  beqz      $v0, .L802AA67C
/* 41F3E8 802AA658 AFBF0010 */   sw       $ra, 0x10($sp)
/* 41F3EC 802AA65C 00031080 */  sll       $v0, $v1, 2
/* 41F3F0 802AA660 3C01802B */  lui       $at, 0x802b
/* 41F3F4 802AA664 00220821 */  addu      $at, $at, $v0
/* 41F3F8 802AA668 8C22CC38 */  lw        $v0, -0x33c8($at)
/* 41F3FC 802AA66C 00400008 */  jr        $v0
/* 41F400 802AA670 00000000 */   nop      
/* 41F404 802AA674 0C0A8715 */  jal       draw_battle_wheel
/* 41F408 802AA678 00000000 */   nop      
.L802AA67C:
/* 41F40C 802AA67C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 41F410 802AA680 03E00008 */  jr        $ra
/* 41F414 802AA684 27BD0018 */   addiu    $sp, $sp, 0x18
