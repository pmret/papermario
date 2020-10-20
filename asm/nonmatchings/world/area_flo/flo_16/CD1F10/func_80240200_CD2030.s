.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240200_CD2030
/* CD2030 80240200 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CD2034 80240204 AFB3001C */  sw        $s3, 0x1c($sp)
/* CD2038 80240208 0080982D */  daddu     $s3, $a0, $zero
/* CD203C 8024020C AFB00010 */  sw        $s0, 0x10($sp)
/* CD2040 80240210 24100001 */  addiu     $s0, $zero, 1
/* CD2044 80240214 AFB40020 */  sw        $s4, 0x20($sp)
/* CD2048 80240218 2414FFFF */  addiu     $s4, $zero, -1
/* CD204C 8024021C AFB50024 */  sw        $s5, 0x24($sp)
/* CD2050 80240220 0200A82D */  daddu     $s5, $s0, $zero
/* CD2054 80240224 AFB10014 */  sw        $s1, 0x14($sp)
/* CD2058 80240228 3C118011 */  lui       $s1, 0x8011
/* CD205C 8024022C 2631F298 */  addiu     $s1, $s1, -0xd68
/* CD2060 80240230 AFBF0028 */  sw        $ra, 0x28($sp)
/* CD2064 80240234 AFB20018 */  sw        $s2, 0x18($sp)
/* CD2068 80240238 8E6200B4 */  lw        $v0, 0xb4($s3)
/* CD206C 8024023C 0280182D */  daddu     $v1, $s4, $zero
/* CD2070 80240240 AE630084 */  sw        $v1, 0x84($s3)
/* CD2074 80240244 00021027 */  nor       $v0, $zero, $v0
/* CD2078 80240248 000217C2 */  srl       $v0, $v0, 0x1f
/* CD207C 8024024C 00029400 */  sll       $s2, $v0, 0x10
.L80240250:
/* CD2080 80240250 92220014 */  lbu       $v0, 0x14($s1)
/* CD2084 80240254 50400008 */  beql      $v0, $zero, .L80240278
/* CD2088 80240258 26100001 */   addiu    $s0, $s0, 1
/* CD208C 8024025C 0200202D */  daddu     $a0, $s0, $zero
/* CD2090 80240260 0C09006D */  jal       func_802401B4
/* CD2094 80240264 00122C03 */   sra      $a1, $s2, 0x10
/* CD2098 80240268 10540003 */  beq       $v0, $s4, .L80240278
/* CD209C 8024026C 26100001 */   addiu    $s0, $s0, 1
/* CD20A0 80240270 080900A1 */  j         .L80240284
/* CD20A4 80240274 AE750084 */   sw       $s5, 0x84($s3)
.L80240278:
/* CD20A8 80240278 2A02000C */  slti      $v0, $s0, 0xc
/* CD20AC 8024027C 1440FFF4 */  bnez      $v0, .L80240250
/* CD20B0 80240280 26310008 */   addiu    $s1, $s1, 8
.L80240284:
/* CD20B4 80240284 8FBF0028 */  lw        $ra, 0x28($sp)
/* CD20B8 80240288 8FB50024 */  lw        $s5, 0x24($sp)
/* CD20BC 8024028C 8FB40020 */  lw        $s4, 0x20($sp)
/* CD20C0 80240290 8FB3001C */  lw        $s3, 0x1c($sp)
/* CD20C4 80240294 8FB20018 */  lw        $s2, 0x18($sp)
/* CD20C8 80240298 8FB10014 */  lw        $s1, 0x14($sp)
/* CD20CC 8024029C 8FB00010 */  lw        $s0, 0x10($sp)
/* CD20D0 802402A0 24020002 */  addiu     $v0, $zero, 2
/* CD20D4 802402A4 03E00008 */  jr        $ra
/* CD20D8 802402A8 27BD0030 */   addiu    $sp, $sp, 0x30
