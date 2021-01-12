.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240148_BB5B28
/* BB5B28 80240148 10A00002 */  beqz      $a1, .L80240154
/* BB5B2C 8024014C 0000302D */   daddu    $a2, $zero, $zero
/* BB5B30 80240150 AC800074 */  sw        $zero, 0x74($a0)
.L80240154:
/* BB5B34 80240154 8C820074 */  lw        $v0, 0x74($a0)
/* BB5B38 80240158 24420004 */  addiu     $v0, $v0, 4
/* BB5B3C 8024015C AC820074 */  sw        $v0, 0x74($a0)
/* BB5B40 80240160 284200F0 */  slti      $v0, $v0, 0xf0
/* BB5B44 80240164 14400004 */  bnez      $v0, .L80240178
/* BB5B48 80240168 00000000 */   nop
/* BB5B4C 8024016C 240200F0 */  addiu     $v0, $zero, 0xf0
/* BB5B50 80240170 AC820074 */  sw        $v0, 0x74($a0)
/* BB5B54 80240174 24060002 */  addiu     $a2, $zero, 2
.L80240178:
/* BB5B58 80240178 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* BB5B5C 8024017C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* BB5B60 80240180 94820076 */  lhu       $v0, 0x76($a0)
/* BB5B64 80240184 A462015C */  sh        $v0, 0x15c($v1)
/* BB5B68 80240188 03E00008 */  jr        $ra
/* BB5B6C 8024018C 00C0102D */   daddu    $v0, $a2, $zero
