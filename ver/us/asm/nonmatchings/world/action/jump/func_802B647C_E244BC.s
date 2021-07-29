.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B647C_E244BC
/* E244BC 802B647C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E244C0 802B6480 AFB00010 */  sw        $s0, 0x10($sp)
/* E244C4 802B6484 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E244C8 802B6488 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E244CC 802B648C AFBF0014 */  sw        $ra, 0x14($sp)
/* E244D0 802B6490 8E030000 */  lw        $v1, ($s0)
/* E244D4 802B6494 04610015 */  bgez      $v1, .L802B64EC
/* E244D8 802B6498 3C027FFF */   lui      $v0, 0x7fff
/* E244DC 802B649C 3442FFFF */  ori       $v0, $v0, 0xffff
/* E244E0 802B64A0 3C04000A */  lui       $a0, 0xa
/* E244E4 802B64A4 34840006 */  ori       $a0, $a0, 6
/* E244E8 802B64A8 00621024 */  and       $v0, $v1, $v0
/* E244EC 802B64AC 2403FFF5 */  addiu     $v1, $zero, -0xb
/* E244F0 802B64B0 00431024 */  and       $v0, $v0, $v1
/* E244F4 802B64B4 8E030004 */  lw        $v1, 4($s0)
/* E244F8 802B64B8 34420004 */  ori       $v0, $v0, 4
/* E244FC 802B64BC 30631000 */  andi      $v1, $v1, 0x1000
/* E24500 802B64C0 14600003 */  bnez      $v1, .L802B64D0
/* E24504 802B64C4 AE020000 */   sw       $v0, ($s0)
/* E24508 802B64C8 3C040001 */  lui       $a0, 1
/* E2450C 802B64CC 34840008 */  ori       $a0, $a0, 8
.L802B64D0:
/* E24510 802B64D0 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E24514 802B64D4 00000000 */   nop
/* E24518 802B64D8 3C03800B */  lui       $v1, %hi(gCameras)
/* E2451C 802B64DC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E24520 802B64E0 94620002 */  lhu       $v0, 2($v1)
/* E24524 802B64E4 34420001 */  ori       $v0, $v0, 1
/* E24528 802B64E8 A4620002 */  sh        $v0, 2($v1)
.L802B64EC:
/* E2452C 802B64EC 960200C0 */  lhu       $v0, 0xc0($s0)
/* E24530 802B64F0 24420001 */  addiu     $v0, $v0, 1
/* E24534 802B64F4 A60200C0 */  sh        $v0, 0xc0($s0)
/* E24538 802B64F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2453C 802B64FC 8FB00010 */  lw        $s0, 0x10($sp)
/* E24540 802B6500 03E00008 */  jr        $ra
/* E24544 802B6504 27BD0018 */   addiu    $sp, $sp, 0x18
