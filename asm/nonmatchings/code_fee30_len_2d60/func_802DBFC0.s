.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DBFC0
/* FF0B0 802DBFC0 0000202D */  daddu     $a0, $zero, $zero
/* FF0B4 802DBFC4 2405FFFF */  addiu     $a1, $zero, -1
/* FF0B8 802DBFC8 3C03802E */  lui       $v1, 0x802e
/* FF0BC 802DBFCC 2463FE48 */  addiu     $v1, $v1, -0x1b8
.L802DBFD0:
/* FF0C0 802DBFD0 8C620000 */  lw        $v0, ($v1)
/* FF0C4 802DBFD4 50450007 */  beql      $v0, $a1, .L802DBFF4
/* FF0C8 802DBFD8 24840001 */   addiu    $a0, $a0, 1
/* FF0CC 802DBFDC 2442FFFF */  addiu     $v0, $v0, -1
/* FF0D0 802DBFE0 AC620000 */  sw        $v0, ($v1)
/* FF0D4 802DBFE4 3042FFFF */  andi      $v0, $v0, 0xffff
/* FF0D8 802DBFE8 50400001 */  beql      $v0, $zero, .L802DBFF0
/* FF0DC 802DBFEC AC650000 */   sw       $a1, ($v1)
.L802DBFF0:
/* FF0E0 802DBFF0 24840001 */  addiu     $a0, $a0, 1
.L802DBFF4:
/* FF0E4 802DBFF4 28820016 */  slti      $v0, $a0, 0x16
/* FF0E8 802DBFF8 1440FFF5 */  bnez      $v0, .L802DBFD0
/* FF0EC 802DBFFC 24630004 */   addiu    $v1, $v1, 4
/* FF0F0 802DC000 03E00008 */  jr        $ra
/* FF0F4 802DC004 00000000 */   nop      
