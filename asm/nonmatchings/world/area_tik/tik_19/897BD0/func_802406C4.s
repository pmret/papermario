.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C4
/* 897CA4 802406C4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 897CA8 802406C8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 897CAC 802406CC 000420C0 */  sll       $a0, $a0, 3
/* 897CB0 802406D0 00822021 */  addu      $a0, $a0, $v0
/* 897CB4 802406D4 90820014 */  lbu       $v0, 0x14($a0)
/* 897CB8 802406D8 10400009 */  beqz      $v0, .L80240700
/* 897CBC 802406DC 00000000 */   nop      
/* 897CC0 802406E0 90820015 */  lbu       $v0, 0x15($a0)
/* 897CC4 802406E4 00022600 */  sll       $a0, $v0, 0x18
/* 897CC8 802406E8 00041E03 */  sra       $v1, $a0, 0x18
/* 897CCC 802406EC 00051400 */  sll       $v0, $a1, 0x10
/* 897CD0 802406F0 00021403 */  sra       $v0, $v0, 0x10
/* 897CD4 802406F4 0043102A */  slt       $v0, $v0, $v1
/* 897CD8 802406F8 10400003 */  beqz      $v0, .L80240708
/* 897CDC 802406FC 00000000 */   nop      
.L80240700:
/* 897CE0 80240700 03E00008 */  jr        $ra
/* 897CE4 80240704 2402FFFF */   addiu    $v0, $zero, -1
.L80240708:
/* 897CE8 80240708 03E00008 */  jr        $ra
/* 897CEC 8024070C 00041603 */   sra      $v0, $a0, 0x18
