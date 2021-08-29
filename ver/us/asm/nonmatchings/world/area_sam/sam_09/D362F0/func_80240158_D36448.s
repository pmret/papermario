.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_D36448
/* D36448 80240158 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3644C 8024015C AFB10014 */  sw        $s1, 0x14($sp)
/* D36450 80240160 0080882D */  daddu     $s1, $a0, $zero
/* D36454 80240164 3C05FD05 */  lui       $a1, 0xfd05
/* D36458 80240168 34A50F80 */  ori       $a1, $a1, 0xf80
/* D3645C 8024016C AFBF001C */  sw        $ra, 0x1c($sp)
/* D36460 80240170 AFB20018 */  sw        $s2, 0x18($sp)
/* D36464 80240174 0C0B1EAF */  jal       get_variable
/* D36468 80240178 AFB00010 */   sw       $s0, 0x10($sp)
/* D3646C 8024017C 0040802D */  daddu     $s0, $v0, $zero
/* D36470 80240180 2412FFFF */  addiu     $s2, $zero, -1
/* D36474 80240184 52120001 */  beql      $s0, $s2, .L8024018C
/* D36478 80240188 241000FF */   addiu    $s0, $zero, 0xff
.L8024018C:
/* D3647C 8024018C 0220202D */  daddu     $a0, $s1, $zero
/* D36480 80240190 3C05F5DE */  lui       $a1, 0xf5de
/* D36484 80240194 34A50288 */  ori       $a1, $a1, 0x288
/* D36488 80240198 0C0B2026 */  jal       evt_set_variable
/* D3648C 8024019C 320600FF */   andi     $a2, $s0, 0xff
/* D36490 802401A0 0220202D */  daddu     $a0, $s1, $zero
/* D36494 802401A4 3C05F5DE */  lui       $a1, 0xf5de
/* D36498 802401A8 34A50289 */  ori       $a1, $a1, 0x289
/* D3649C 802401AC 00103203 */  sra       $a2, $s0, 8
/* D364A0 802401B0 0C0B2026 */  jal       evt_set_variable
/* D364A4 802401B4 30C600FF */   andi     $a2, $a2, 0xff
/* D364A8 802401B8 0220202D */  daddu     $a0, $s1, $zero
/* D364AC 802401BC 3C05FD05 */  lui       $a1, 0xfd05
/* D364B0 802401C0 0C0B1EAF */  jal       get_variable
/* D364B4 802401C4 34A50F81 */   ori      $a1, $a1, 0xf81
/* D364B8 802401C8 0040802D */  daddu     $s0, $v0, $zero
/* D364BC 802401CC 52120001 */  beql      $s0, $s2, .L802401D4
/* D364C0 802401D0 241000FF */   addiu    $s0, $zero, 0xff
.L802401D4:
/* D364C4 802401D4 0220202D */  daddu     $a0, $s1, $zero
/* D364C8 802401D8 3C05F5DE */  lui       $a1, 0xf5de
/* D364CC 802401DC 34A5028A */  ori       $a1, $a1, 0x28a
/* D364D0 802401E0 0C0B2026 */  jal       evt_set_variable
/* D364D4 802401E4 320600FF */   andi     $a2, $s0, 0xff
/* D364D8 802401E8 0220202D */  daddu     $a0, $s1, $zero
/* D364DC 802401EC 3C05F5DE */  lui       $a1, 0xf5de
/* D364E0 802401F0 34A5028B */  ori       $a1, $a1, 0x28b
/* D364E4 802401F4 00103203 */  sra       $a2, $s0, 8
/* D364E8 802401F8 0C0B2026 */  jal       evt_set_variable
/* D364EC 802401FC 30C600FF */   andi     $a2, $a2, 0xff
/* D364F0 80240200 0220202D */  daddu     $a0, $s1, $zero
/* D364F4 80240204 3C05FD05 */  lui       $a1, 0xfd05
/* D364F8 80240208 0C0B1EAF */  jal       get_variable
/* D364FC 8024020C 34A50F82 */   ori      $a1, $a1, 0xf82
/* D36500 80240210 0040802D */  daddu     $s0, $v0, $zero
/* D36504 80240214 52120001 */  beql      $s0, $s2, .L8024021C
/* D36508 80240218 241000FF */   addiu    $s0, $zero, 0xff
.L8024021C:
/* D3650C 8024021C 0220202D */  daddu     $a0, $s1, $zero
/* D36510 80240220 3C05F5DE */  lui       $a1, 0xf5de
/* D36514 80240224 34A5028C */  ori       $a1, $a1, 0x28c
/* D36518 80240228 0C0B2026 */  jal       evt_set_variable
/* D3651C 8024022C 320600FF */   andi     $a2, $s0, 0xff
/* D36520 80240230 0220202D */  daddu     $a0, $s1, $zero
/* D36524 80240234 3C05F5DE */  lui       $a1, 0xf5de
/* D36528 80240238 34A5028D */  ori       $a1, $a1, 0x28d
/* D3652C 8024023C 00103203 */  sra       $a2, $s0, 8
/* D36530 80240240 0C0B2026 */  jal       evt_set_variable
/* D36534 80240244 30C600FF */   andi     $a2, $a2, 0xff
/* D36538 80240248 8FBF001C */  lw        $ra, 0x1c($sp)
/* D3653C 8024024C 8FB20018 */  lw        $s2, 0x18($sp)
/* D36540 80240250 8FB10014 */  lw        $s1, 0x14($sp)
/* D36544 80240254 8FB00010 */  lw        $s0, 0x10($sp)
/* D36548 80240258 24020002 */  addiu     $v0, $zero, 2
/* D3654C 8024025C 03E00008 */  jr        $ra
/* D36550 80240260 27BD0020 */   addiu    $sp, $sp, 0x20
