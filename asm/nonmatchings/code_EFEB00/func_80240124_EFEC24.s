.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240124_EFEC24
/* EFEC24 80240124 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EFEC28 80240128 AFB00010 */  sw        $s0, 0x10($sp)
/* EFEC2C 8024012C 0080802D */  daddu     $s0, $a0, $zero
/* EFEC30 80240130 10A00005 */  beqz      $a1, .L80240148
/* EFEC34 80240134 AFBF0014 */   sw       $ra, 0x14($sp)
/* EFEC38 80240138 AE000070 */  sw        $zero, 0x70($s0)
/* EFEC3C 8024013C AE000074 */  sw        $zero, 0x74($s0)
/* EFEC40 80240140 AE000078 */  sw        $zero, 0x78($s0)
/* EFEC44 80240144 AE00007C */  sw        $zero, 0x7c($s0)
.L80240148:
/* EFEC48 80240148 8E020070 */  lw        $v0, 0x70($s0)
/* EFEC4C 8024014C 1440000E */  bnez      $v0, .L80240188
/* EFEC50 80240150 00000000 */   nop      
/* EFEC54 80240154 8E0300A8 */  lw        $v1, 0xa8($s0)
/* EFEC58 80240158 8E020088 */  lw        $v0, 0x88($s0)
/* EFEC5C 8024015C 00621821 */  addu      $v1, $v1, $v0
/* EFEC60 80240160 04610004 */  bgez      $v1, .L80240174
/* EFEC64 80240164 AE0300A8 */   sw       $v1, 0xa8($s0)
/* EFEC68 80240168 3C020002 */  lui       $v0, 2
/* EFEC6C 8024016C 08090061 */  j         .L80240184
/* EFEC70 80240170 00621021 */   addu     $v0, $v1, $v0
.L80240174:
/* EFEC74 80240174 3C040002 */  lui       $a0, 2
/* EFEC78 80240178 0083102A */  slt       $v0, $a0, $v1
/* EFEC7C 8024017C 10400002 */  beqz      $v0, .L80240188
/* EFEC80 80240180 00641023 */   subu     $v0, $v1, $a0
.L80240184:
/* EFEC84 80240184 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240188:
/* EFEC88 80240188 8E020074 */  lw        $v0, 0x74($s0)
/* EFEC8C 8024018C 1440000E */  bnez      $v0, .L802401C8
/* EFEC90 80240190 00000000 */   nop      
/* EFEC94 80240194 8E0300AC */  lw        $v1, 0xac($s0)
/* EFEC98 80240198 8E02008C */  lw        $v0, 0x8c($s0)
/* EFEC9C 8024019C 00621821 */  addu      $v1, $v1, $v0
/* EFECA0 802401A0 04610004 */  bgez      $v1, .L802401B4
/* EFECA4 802401A4 AE0300AC */   sw       $v1, 0xac($s0)
/* EFECA8 802401A8 3C020002 */  lui       $v0, 2
/* EFECAC 802401AC 08090071 */  j         .L802401C4
/* EFECB0 802401B0 00621021 */   addu     $v0, $v1, $v0
.L802401B4:
/* EFECB4 802401B4 3C040002 */  lui       $a0, 2
/* EFECB8 802401B8 0083102A */  slt       $v0, $a0, $v1
/* EFECBC 802401BC 10400002 */  beqz      $v0, .L802401C8
/* EFECC0 802401C0 00641023 */   subu     $v0, $v1, $a0
.L802401C4:
/* EFECC4 802401C4 AE0200AC */  sw        $v0, 0xac($s0)
.L802401C8:
/* EFECC8 802401C8 8E020078 */  lw        $v0, 0x78($s0)
/* EFECCC 802401CC 1440000E */  bnez      $v0, .L80240208
/* EFECD0 802401D0 00000000 */   nop      
/* EFECD4 802401D4 8E0300B0 */  lw        $v1, 0xb0($s0)
/* EFECD8 802401D8 8E020090 */  lw        $v0, 0x90($s0)
/* EFECDC 802401DC 00621821 */  addu      $v1, $v1, $v0
/* EFECE0 802401E0 04610004 */  bgez      $v1, .L802401F4
/* EFECE4 802401E4 AE0300B0 */   sw       $v1, 0xb0($s0)
/* EFECE8 802401E8 3C020002 */  lui       $v0, 2
/* EFECEC 802401EC 08090081 */  j         .L80240204
/* EFECF0 802401F0 00621021 */   addu     $v0, $v1, $v0
.L802401F4:
/* EFECF4 802401F4 3C040002 */  lui       $a0, 2
/* EFECF8 802401F8 0083102A */  slt       $v0, $a0, $v1
/* EFECFC 802401FC 10400002 */  beqz      $v0, .L80240208
/* EFED00 80240200 00641023 */   subu     $v0, $v1, $a0
.L80240204:
/* EFED04 80240204 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80240208:
/* EFED08 80240208 8E02007C */  lw        $v0, 0x7c($s0)
/* EFED0C 8024020C 1440000E */  bnez      $v0, .L80240248
/* EFED10 80240210 00000000 */   nop      
/* EFED14 80240214 8E0300B4 */  lw        $v1, 0xb4($s0)
/* EFED18 80240218 8E020094 */  lw        $v0, 0x94($s0)
/* EFED1C 8024021C 00621821 */  addu      $v1, $v1, $v0
/* EFED20 80240220 04610004 */  bgez      $v1, .L80240234
/* EFED24 80240224 AE0300B4 */   sw       $v1, 0xb4($s0)
/* EFED28 80240228 3C020002 */  lui       $v0, 2
/* EFED2C 8024022C 08090091 */  j         .L80240244
/* EFED30 80240230 00621021 */   addu     $v0, $v1, $v0
.L80240234:
/* EFED34 80240234 3C040002 */  lui       $a0, 2
/* EFED38 80240238 0083102A */  slt       $v0, $a0, $v1
/* EFED3C 8024023C 10400002 */  beqz      $v0, .L80240248
/* EFED40 80240240 00641023 */   subu     $v0, $v1, $a0
.L80240244:
/* EFED44 80240244 AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240248:
/* EFED48 80240248 8E040084 */  lw        $a0, 0x84($s0)
/* EFED4C 8024024C 0C049819 */  jal       func_80126064
/* EFED50 80240250 8E0500A8 */   lw       $a1, 0xa8($s0)
/* EFED54 80240254 8E040084 */  lw        $a0, 0x84($s0)
/* EFED58 80240258 0C04981F */  jal       func_8012607C
/* EFED5C 8024025C 8E0500AC */   lw       $a1, 0xac($s0)
/* EFED60 80240260 8E040084 */  lw        $a0, 0x84($s0)
/* EFED64 80240264 0C049825 */  jal       func_80126094
/* EFED68 80240268 8E0500B0 */   lw       $a1, 0xb0($s0)
/* EFED6C 8024026C 8E040084 */  lw        $a0, 0x84($s0)
/* EFED70 80240270 0C04982B */  jal       func_801260AC
/* EFED74 80240274 8E0500B4 */   lw       $a1, 0xb4($s0)
/* EFED78 80240278 8E020070 */  lw        $v0, 0x70($s0)
/* EFED7C 8024027C 8E030078 */  lw        $v1, 0x78($s0)
/* EFED80 80240280 8E040098 */  lw        $a0, 0x98($s0)
/* EFED84 80240284 24420001 */  addiu     $v0, $v0, 1
/* EFED88 80240288 AE020070 */  sw        $v0, 0x70($s0)
/* EFED8C 8024028C 8E020074 */  lw        $v0, 0x74($s0)
/* EFED90 80240290 24630001 */  addiu     $v1, $v1, 1
/* EFED94 80240294 AE030078 */  sw        $v1, 0x78($s0)
/* EFED98 80240298 8E030070 */  lw        $v1, 0x70($s0)
/* EFED9C 8024029C 24420001 */  addiu     $v0, $v0, 1
/* EFEDA0 802402A0 AE020074 */  sw        $v0, 0x74($s0)
/* EFEDA4 802402A4 8E02007C */  lw        $v0, 0x7c($s0)
/* EFEDA8 802402A8 0064182A */  slt       $v1, $v1, $a0
/* EFEDAC 802402AC 24420001 */  addiu     $v0, $v0, 1
/* EFEDB0 802402B0 14600002 */  bnez      $v1, .L802402BC
/* EFEDB4 802402B4 AE02007C */   sw       $v0, 0x7c($s0)
/* EFEDB8 802402B8 AE000070 */  sw        $zero, 0x70($s0)
.L802402BC:
/* EFEDBC 802402BC 8E020074 */  lw        $v0, 0x74($s0)
/* EFEDC0 802402C0 8E03009C */  lw        $v1, 0x9c($s0)
/* EFEDC4 802402C4 0043102A */  slt       $v0, $v0, $v1
/* EFEDC8 802402C8 50400001 */  beql      $v0, $zero, .L802402D0
/* EFEDCC 802402CC AE000074 */   sw       $zero, 0x74($s0)
.L802402D0:
/* EFEDD0 802402D0 8E020078 */  lw        $v0, 0x78($s0)
/* EFEDD4 802402D4 8E0300A0 */  lw        $v1, 0xa0($s0)
/* EFEDD8 802402D8 0043102A */  slt       $v0, $v0, $v1
/* EFEDDC 802402DC 50400001 */  beql      $v0, $zero, .L802402E4
/* EFEDE0 802402E0 AE000078 */   sw       $zero, 0x78($s0)
.L802402E4:
/* EFEDE4 802402E4 8E02007C */  lw        $v0, 0x7c($s0)
/* EFEDE8 802402E8 8E0300A4 */  lw        $v1, 0xa4($s0)
/* EFEDEC 802402EC 0043102A */  slt       $v0, $v0, $v1
/* EFEDF0 802402F0 50400001 */  beql      $v0, $zero, .L802402F8
/* EFEDF4 802402F4 AE00007C */   sw       $zero, 0x7c($s0)
.L802402F8:
/* EFEDF8 802402F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* EFEDFC 802402FC 8FB00010 */  lw        $s0, 0x10($sp)
/* EFEE00 80240300 0000102D */  daddu     $v0, $zero, $zero
/* EFEE04 80240304 03E00008 */  jr        $ra
/* EFEE08 80240308 27BD0018 */   addiu    $sp, $sp, 0x18
