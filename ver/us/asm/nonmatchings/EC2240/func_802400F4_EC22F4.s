.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F4_EC22F4
/* EC22F4 802400F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC22F8 802400F8 AFB00010 */  sw        $s0, 0x10($sp)
/* EC22FC 802400FC 0080802D */  daddu     $s0, $a0, $zero
/* EC2300 80240100 AFBF0018 */  sw        $ra, 0x18($sp)
/* EC2304 80240104 AFB10014 */  sw        $s1, 0x14($sp)
/* EC2308 80240108 8E02000C */  lw        $v0, 0xc($s0)
/* EC230C 8024010C 8C510000 */  lw        $s1, ($v0)
/* EC2310 80240110 0C0B53A3 */  jal       dead_get_variable
/* EC2314 80240114 0220282D */   daddu    $a1, $s1, $zero
/* EC2318 80240118 3C03FFF0 */  lui       $v1, 0xfff0
/* EC231C 8024011C 3463FFFF */  ori       $v1, $v1, 0xffff
/* EC2320 80240120 0200202D */  daddu     $a0, $s0, $zero
/* EC2324 80240124 00431024 */  and       $v0, $v0, $v1
/* EC2328 80240128 00021140 */  sll       $v0, $v0, 5
/* EC232C 8024012C 3C068009 */  lui       $a2, %hi(D_8008D2C0)
/* EC2330 80240130 00C23021 */  addu      $a2, $a2, $v0
/* EC2334 80240134 8CC6D2C0 */  lw        $a2, %lo(D_8008D2C0)($a2)
/* EC2338 80240138 0C0B551A */  jal       dead_set_variable
/* EC233C 8024013C 0220282D */   daddu    $a1, $s1, $zero
/* EC2340 80240140 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC2344 80240144 8FB10014 */  lw        $s1, 0x14($sp)
/* EC2348 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* EC234C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* EC2350 80240150 03E00008 */  jr        $ra
/* EC2354 80240154 27BD0020 */   addiu    $sp, $sp, 0x20
