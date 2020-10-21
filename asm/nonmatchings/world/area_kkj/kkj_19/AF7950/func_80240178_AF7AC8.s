.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240178_AF7AC8
/* AF7AC8 80240178 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF7ACC 8024017C 3C038024 */  lui       $v1, 0x8024
/* AF7AD0 80240180 8C630E90 */  lw        $v1, 0xe90($v1)
/* AF7AD4 80240184 3C048024 */  lui       $a0, 0x8024
/* AF7AD8 80240188 24840E10 */  addiu     $a0, $a0, 0xe10
/* AF7ADC 8024018C AFBF0018 */  sw        $ra, 0x18($sp)
/* AF7AE0 80240190 00031040 */  sll       $v0, $v1, 1
/* AF7AE4 80240194 00431021 */  addu      $v0, $v0, $v1
/* AF7AE8 80240198 00021080 */  sll       $v0, $v0, 2
/* AF7AEC 8024019C 00443821 */  addu      $a3, $v0, $a0
/* AF7AF0 802401A0 3C048008 */  lui       $a0, %hi(gItemTable)
/* AF7AF4 802401A4 248478E0 */  addiu     $a0, $a0, %lo(gItemTable)
/* AF7AF8 802401A8 8CE20000 */  lw        $v0, ($a3)
/* AF7AFC 802401AC 8CE30008 */  lw        $v1, 8($a3)
/* AF7B00 802401B0 00021140 */  sll       $v0, $v0, 5
/* AF7B04 802401B4 10600007 */  beqz      $v1, .L802401D4
/* AF7B08 802401B8 00442021 */   addu     $a0, $v0, $a0
/* AF7B0C 802401BC 2402000A */  addiu     $v0, $zero, 0xa
/* AF7B10 802401C0 AFA20010 */  sw        $v0, 0x10($sp)
/* AF7B14 802401C4 AFA00014 */  sw        $zero, 0x14($sp)
/* AF7B18 802401C8 8CE40008 */  lw        $a0, 8($a3)
/* AF7B1C 802401CC 0809007A */  j         .L802401E8
/* AF7B20 802401D0 24A50008 */   addiu    $a1, $a1, 8
.L802401D4:
/* AF7B24 802401D4 24A50008 */  addiu     $a1, $a1, 8
/* AF7B28 802401D8 2402000A */  addiu     $v0, $zero, 0xa
/* AF7B2C 802401DC AFA20010 */  sw        $v0, 0x10($sp)
/* AF7B30 802401E0 AFA00014 */  sw        $zero, 0x14($sp)
/* AF7B34 802401E4 8C840014 */  lw        $a0, 0x14($a0)
.L802401E8:
/* AF7B38 802401E8 0C04993B */  jal       draw_string
/* AF7B3C 802401EC 240700FF */   addiu    $a3, $zero, 0xff
/* AF7B40 802401F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* AF7B44 802401F4 03E00008 */  jr        $ra
/* AF7B48 802401F8 27BD0020 */   addiu    $sp, $sp, 0x20
