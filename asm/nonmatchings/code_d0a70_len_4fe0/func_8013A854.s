.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A854
/* D0F54 8013A854 2C82005A */  sltiu     $v0, $a0, 0x5a
/* D0F58 8013A858 10400009 */  beqz      $v0, .L8013A880
/* D0F5C 8013A85C 00041140 */   sll      $v0, $a0, 5
/* D0F60 8013A860 00441023 */  subu      $v0, $v0, $a0
/* D0F64 8013A864 3C038015 */  lui       $v1, 0x8015
/* D0F68 8013A868 8C636954 */  lw        $v1, 0x6954($v1)
/* D0F6C 8013A86C 00021080 */  sll       $v0, $v0, 2
/* D0F70 8013A870 00431021 */  addu      $v0, $v0, $v1
/* D0F74 8013A874 2403FFFF */  addiu     $v1, $zero, -1
/* D0F78 8013A878 AC400014 */  sw        $zero, 0x14($v0)
/* D0F7C 8013A87C A4430010 */  sh        $v1, 0x10($v0)
.L8013A880:
/* D0F80 8013A880 03E00008 */  jr        $ra
/* D0F84 8013A884 00000000 */   nop      
