.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240864_DDD094
/* DDD094 80240864 3C028011 */  lui       $v0, %hi(gPlayerData)
/* DDD098 80240868 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* DDD09C 8024086C 000420C0 */  sll       $a0, $a0, 3
/* DDD0A0 80240870 00822021 */  addu      $a0, $a0, $v0
/* DDD0A4 80240874 90820014 */  lbu       $v0, 0x14($a0)
/* DDD0A8 80240878 10400009 */  beqz      $v0, .L802408A0
/* DDD0AC 8024087C 00000000 */   nop      
/* DDD0B0 80240880 90820015 */  lbu       $v0, 0x15($a0)
/* DDD0B4 80240884 00022600 */  sll       $a0, $v0, 0x18
/* DDD0B8 80240888 00041E03 */  sra       $v1, $a0, 0x18
/* DDD0BC 8024088C 00051400 */  sll       $v0, $a1, 0x10
/* DDD0C0 80240890 00021403 */  sra       $v0, $v0, 0x10
/* DDD0C4 80240894 0043102A */  slt       $v0, $v0, $v1
/* DDD0C8 80240898 10400003 */  beqz      $v0, .L802408A8
/* DDD0CC 8024089C 00000000 */   nop      
.L802408A0:
/* DDD0D0 802408A0 03E00008 */  jr        $ra
/* DDD0D4 802408A4 2402FFFF */   addiu    $v0, $zero, -1
.L802408A8:
/* DDD0D8 802408A8 03E00008 */  jr        $ra
/* DDD0DC 802408AC 00041603 */   sra      $v0, $a0, 0x18
