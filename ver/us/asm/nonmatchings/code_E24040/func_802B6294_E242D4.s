.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6294_E242D4
/* E242D4 802B6294 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E242D8 802B6298 AFB00010 */  sw        $s0, 0x10($sp)
/* E242DC 802B629C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E242E0 802B62A0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E242E4 802B62A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* E242E8 802B62A8 8E050004 */  lw        $a1, 4($s0)
/* E242EC 802B62AC 30A21000 */  andi      $v0, $a1, 0x1000
/* E242F0 802B62B0 10400005 */  beqz      $v0, .L802B62C8
/* E242F4 802B62B4 00000000 */   nop
/* E242F8 802B62B8 0C0AD91F */  jal       func_802B647C_E244BC
/* E242FC 802B62BC 00000000 */   nop
/* E24300 802B62C0 080AD8CE */  j         .L802B6338
/* E24304 802B62C4 00000000 */   nop
.L802B62C8:
/* E24308 802B62C8 8E030000 */  lw        $v1, ($s0)
/* E2430C 802B62CC 04610017 */  bgez      $v1, .L802B632C
/* E24310 802B62D0 3C027FFF */   lui      $v0, 0x7fff
/* E24314 802B62D4 3442FFF5 */  ori       $v0, $v0, 0xfff5
/* E24318 802B62D8 00621024 */  and       $v0, $v1, $v0
/* E2431C 802B62DC 34420004 */  ori       $v0, $v0, 4
/* E24320 802B62E0 AE020000 */  sw        $v0, ($s0)
/* E24324 802B62E4 30A24000 */  andi      $v0, $a1, 0x4000
/* E24328 802B62E8 10400003 */  beqz      $v0, .L802B62F8
/* E2432C 802B62EC 3C040009 */   lui      $a0, 9
/* E24330 802B62F0 080AD8C4 */  j         .L802B6310
/* E24334 802B62F4 34840005 */   ori      $a0, $a0, 5
.L802B62F8:
/* E24338 802B62F8 3C040006 */  lui       $a0, 6
/* E2433C 802B62FC 30A20003 */  andi      $v0, $a1, 3
/* E24340 802B6300 14400003 */  bnez      $v0, .L802B6310
/* E24344 802B6304 3484000A */   ori      $a0, $a0, 0xa
/* E24348 802B6308 3C040001 */  lui       $a0, 1
/* E2434C 802B630C 34840008 */  ori       $a0, $a0, 8
.L802B6310:
/* E24350 802B6310 0C037FBF */  jal       func_800DFEFC
/* E24354 802B6314 00000000 */   nop
/* E24358 802B6318 3C03800B */  lui       $v1, %hi(gCameras)
/* E2435C 802B631C 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E24360 802B6320 94620002 */  lhu       $v0, 2($v1)
/* E24364 802B6324 34420001 */  ori       $v0, $v0, 1
/* E24368 802B6328 A4620002 */  sh        $v0, 2($v1)
.L802B632C:
/* E2436C 802B632C 960200C0 */  lhu       $v0, 0xc0($s0)
/* E24370 802B6330 24420001 */  addiu     $v0, $v0, 1
/* E24374 802B6334 A60200C0 */  sh        $v0, 0xc0($s0)
.L802B6338:
/* E24378 802B6338 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2437C 802B633C 8FB00010 */  lw        $s0, 0x10($sp)
/* E24380 802B6340 03E00008 */  jr        $ra
/* E24384 802B6344 27BD0018 */   addiu    $sp, $sp, 0x18
