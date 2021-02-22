.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400EC_BB5ACC
/* BB5ACC 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB5AD0 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* BB5AD4 802400F4 0000802D */  daddu     $s0, $zero, $zero
/* BB5AD8 802400F8 10A00003 */  beqz      $a1, .L80240108
/* BB5ADC 802400FC AFBF0014 */   sw       $ra, 0x14($sp)
/* BB5AE0 80240100 24020424 */  addiu     $v0, $zero, 0x424
/* BB5AE4 80240104 AC820074 */  sw        $v0, 0x74($a0)
.L80240108:
/* BB5AE8 80240108 8C820074 */  lw        $v0, 0x74($a0)
/* BB5AEC 8024010C 2442FFFF */  addiu     $v0, $v0, -1
/* BB5AF0 80240110 AC820074 */  sw        $v0, 0x74($a0)
/* BB5AF4 80240114 284203E9 */  slti      $v0, $v0, 0x3e9
/* BB5AF8 80240118 10400003 */  beqz      $v0, .L80240128
/* BB5AFC 8024011C 240203E8 */   addiu    $v0, $zero, 0x3e8
/* BB5B00 80240120 AC820074 */  sw        $v0, 0x74($a0)
/* BB5B04 80240124 24100002 */  addiu     $s0, $zero, 2
.L80240128:
/* BB5B08 80240128 8C850074 */  lw        $a1, 0x74($a0)
/* BB5B0C 8024012C 0C046EDD */  jal       set_world_fog_dist
/* BB5B10 80240130 240403DE */   addiu    $a0, $zero, 0x3de
/* BB5B14 80240134 0200102D */  daddu     $v0, $s0, $zero
/* BB5B18 80240138 8FBF0014 */  lw        $ra, 0x14($sp)
/* BB5B1C 8024013C 8FB00010 */  lw        $s0, 0x10($sp)
/* BB5B20 80240140 03E00008 */  jr        $ra
/* BB5B24 80240144 27BD0018 */   addiu    $sp, $sp, 0x18
