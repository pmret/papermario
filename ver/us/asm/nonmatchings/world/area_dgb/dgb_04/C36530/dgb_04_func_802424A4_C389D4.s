.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dgb_04_func_802424A4_C389D4
/* C389D4 802424A4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* C389D8 802424A8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* C389DC 802424AC 000420C0 */  sll       $a0, $a0, 3
/* C389E0 802424B0 00822021 */  addu      $a0, $a0, $v0
/* C389E4 802424B4 90820014 */  lbu       $v0, 0x14($a0)
/* C389E8 802424B8 10400009 */  beqz      $v0, .L802424E0
/* C389EC 802424BC 00000000 */   nop
/* C389F0 802424C0 90820015 */  lbu       $v0, 0x15($a0)
/* C389F4 802424C4 00022600 */  sll       $a0, $v0, 0x18
/* C389F8 802424C8 00041E03 */  sra       $v1, $a0, 0x18
/* C389FC 802424CC 00051400 */  sll       $v0, $a1, 0x10
/* C38A00 802424D0 00021403 */  sra       $v0, $v0, 0x10
/* C38A04 802424D4 0043102A */  slt       $v0, $v0, $v1
/* C38A08 802424D8 10400003 */  beqz      $v0, .L802424E8
/* C38A0C 802424DC 00000000 */   nop
.L802424E0:
/* C38A10 802424E0 03E00008 */  jr        $ra
/* C38A14 802424E4 2402FFFF */   addiu    $v0, $zero, -1
.L802424E8:
/* C38A18 802424E8 03E00008 */  jr        $ra
/* C38A1C 802424EC 00041603 */   sra      $v0, $a0, 0x18
