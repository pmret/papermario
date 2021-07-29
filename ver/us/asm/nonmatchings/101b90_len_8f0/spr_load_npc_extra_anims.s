.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_load_npc_extra_anims
/* 1020FC 802DF00C 27BDFE30 */  addiu     $sp, $sp, -0x1d0
/* 102100 802DF010 AFB601C0 */  sw        $s6, 0x1c0($sp)
/* 102104 802DF014 0080B02D */  daddu     $s6, $a0, $zero
/* 102108 802DF018 AFB101AC */  sw        $s1, 0x1ac($sp)
/* 10210C 802DF01C 24110063 */  addiu     $s1, $zero, 0x63
/* 102110 802DF020 27A2019C */  addiu     $v0, $sp, 0x19c
/* 102114 802DF024 AFBF01C8 */  sw        $ra, 0x1c8($sp)
/* 102118 802DF028 AFB701C4 */  sw        $s7, 0x1c4($sp)
/* 10211C 802DF02C AFB501BC */  sw        $s5, 0x1bc($sp)
/* 102120 802DF030 AFB401B8 */  sw        $s4, 0x1b8($sp)
/* 102124 802DF034 AFB301B4 */  sw        $s3, 0x1b4($sp)
/* 102128 802DF038 AFB201B0 */  sw        $s2, 0x1b0($sp)
/* 10212C 802DF03C AFB001A8 */  sw        $s0, 0x1a8($sp)
.L802DF040:
/* 102130 802DF040 AC400000 */  sw        $zero, ($v0)
/* 102134 802DF044 2631FFFF */  addiu     $s1, $s1, -1
/* 102138 802DF048 0621FFFD */  bgez      $s1, .L802DF040
/* 10213C 802DF04C 2442FFFC */   addiu    $v0, $v0, -4
/* 102140 802DF050 8CA30000 */  lw        $v1, ($a1)
/* 102144 802DF054 2402FFFF */  addiu     $v0, $zero, -1
/* 102148 802DF058 1062004B */  beq       $v1, $v0, .L802DF188
/* 10214C 802DF05C 24A50004 */   addiu    $a1, $a1, 4
/* 102150 802DF060 0040602D */  daddu     $t4, $v0, $zero
/* 102154 802DF064 24124000 */  addiu     $s2, $zero, 0x4000
/* 102158 802DF068 24111000 */  addiu     $s1, $zero, 0x1000
/* 10215C 802DF06C 24102000 */  addiu     $s0, $zero, 0x2000
/* 102160 802DF070 240F3000 */  addiu     $t7, $zero, 0x3000
/* 102164 802DF074 240E6000 */  addiu     $t6, $zero, 0x6000
/* 102168 802DF078 240D5000 */  addiu     $t5, $zero, 0x5000
.L802DF07C:
/* 10216C 802DF07C 306200FF */  andi      $v0, $v1, 0xff
/* 102170 802DF080 00021080 */  sll       $v0, $v0, 2
/* 102174 802DF084 02C21021 */  addu      $v0, $s6, $v0
/* 102178 802DF088 080B7C5C */  j         .L802DF170
/* 10217C 802DF08C 8C480010 */   lw       $t0, 0x10($v0)
.L802DF090:
/* 102180 802DF090 94620004 */  lhu       $v0, 4($v1)
/* 102184 802DF094 8C660000 */  lw        $a2, ($v1)
/* 102188 802DF098 00021400 */  sll       $v0, $v0, 0x10
/* 10218C 802DF09C 00021C03 */  sra       $v1, $v0, 0x10
/* 102190 802DF0A0 000217C2 */  srl       $v0, $v0, 0x1f
/* 102194 802DF0A4 00621821 */  addu      $v1, $v1, $v0
/* 102198 802DF0A8 00031843 */  sra       $v1, $v1, 1
/* 10219C 802DF0AC 18600030 */  blez      $v1, .L802DF170
/* 1021A0 802DF0B0 00000000 */   nop
/* 1021A4 802DF0B4 240B7000 */  addiu     $t3, $zero, 0x7000
/* 1021A8 802DF0B8 27A90010 */  addiu     $t1, $sp, 0x10
/* 1021AC 802DF0BC 240A0001 */  addiu     $t2, $zero, 1
.L802DF0C0:
/* 1021B0 802DF0C0 94C70000 */  lhu       $a3, ($a2)
/* 1021B4 802DF0C4 24C60002 */  addiu     $a2, $a2, 2
/* 1021B8 802DF0C8 30E4F000 */  andi      $a0, $a3, 0xf000
/* 1021BC 802DF0CC 10920022 */  beq       $a0, $s2, .L802DF158
/* 1021C0 802DF0D0 2463FFFF */   addiu    $v1, $v1, -1
/* 1021C4 802DF0D4 28824001 */  slti      $v0, $a0, 0x4001
/* 1021C8 802DF0D8 1040000B */  beqz      $v0, .L802DF108
/* 1021CC 802DF0DC 00000000 */   nop
/* 1021D0 802DF0E0 10910015 */  beq       $a0, $s1, .L802DF138
/* 1021D4 802DF0E4 28821001 */   slti     $v0, $a0, 0x1001
/* 1021D8 802DF0E8 1440001F */  bnez      $v0, .L802DF168
/* 1021DC 802DF0EC 00000000 */   nop
/* 1021E0 802DF0F0 1090001D */  beq       $a0, $s0, .L802DF168
/* 1021E4 802DF0F4 00000000 */   nop
/* 1021E8 802DF0F8 508F0016 */  beql      $a0, $t7, .L802DF154
/* 1021EC 802DF0FC 24C60002 */   addiu    $a2, $a2, 2
/* 1021F0 802DF100 080B7C5A */  j         .L802DF168
/* 1021F4 802DF104 00000000 */   nop
.L802DF108:
/* 1021F8 802DF108 108E0017 */  beq       $a0, $t6, .L802DF168
/* 1021FC 802DF10C 28826001 */   slti     $v0, $a0, 0x6001
/* 102200 802DF110 10400005 */  beqz      $v0, .L802DF128
/* 102204 802DF114 00000000 */   nop
/* 102208 802DF118 508D0012 */  beql      $a0, $t5, .L802DF164
/* 10220C 802DF11C 24C60002 */   addiu    $a2, $a2, 2
/* 102210 802DF120 080B7C5A */  j         .L802DF168
/* 102214 802DF124 00000000 */   nop
.L802DF128:
/* 102218 802DF128 508B000E */  beql      $a0, $t3, .L802DF164
/* 10221C 802DF12C 24C60002 */   addiu    $a2, $a2, 2
/* 102220 802DF130 080B7C5A */  j         .L802DF168
/* 102224 802DF134 00000000 */   nop
.L802DF138:
/* 102228 802DF138 30E400FF */  andi      $a0, $a3, 0xff
/* 10222C 802DF13C 28820064 */  slti      $v0, $a0, 0x64
/* 102230 802DF140 10400009 */  beqz      $v0, .L802DF168
/* 102234 802DF144 00041080 */   sll      $v0, $a0, 2
/* 102238 802DF148 01221021 */  addu      $v0, $t1, $v0
/* 10223C 802DF14C 080B7C5A */  j         .L802DF168
/* 102240 802DF150 AC4A0000 */   sw       $t2, ($v0)
.L802DF154:
/* 102244 802DF154 2463FFFF */  addiu     $v1, $v1, -1
.L802DF158:
/* 102248 802DF158 24C60002 */  addiu     $a2, $a2, 2
/* 10224C 802DF15C 2463FFFF */  addiu     $v1, $v1, -1
/* 102250 802DF160 24C60002 */  addiu     $a2, $a2, 2
.L802DF164:
/* 102254 802DF164 2463FFFF */  addiu     $v1, $v1, -1
.L802DF168:
/* 102258 802DF168 1C60FFD5 */  bgtz      $v1, .L802DF0C0
/* 10225C 802DF16C 00000000 */   nop
.L802DF170:
/* 102260 802DF170 8D030000 */  lw        $v1, ($t0)
/* 102264 802DF174 146CFFC6 */  bne       $v1, $t4, .L802DF090
/* 102268 802DF178 25080004 */   addiu    $t0, $t0, 4
/* 10226C 802DF17C 8CA30000 */  lw        $v1, ($a1)
/* 102270 802DF180 146CFFBE */  bne       $v1, $t4, .L802DF07C
/* 102274 802DF184 24A50004 */   addiu    $a1, $a1, 4
.L802DF188:
/* 102278 802DF188 0000882D */  daddu     $s1, $zero, $zero
/* 10227C 802DF18C 8ED30000 */  lw        $s3, ($s6)
/* 102280 802DF190 2417FFFF */  addiu     $s7, $zero, -1
/* 102284 802DF194 8E650000 */  lw        $a1, ($s3)
/* 102288 802DF198 27B40010 */  addiu     $s4, $sp, 0x10
/* 10228C 802DF19C 8CB20000 */  lw        $s2, ($a1)
.L802DF1A0:
/* 102290 802DF1A0 8E650000 */  lw        $a1, ($s3)
/* 102294 802DF1A4 50B70019 */  beql      $a1, $s7, .L802DF20C
/* 102298 802DF1A8 0240302D */   daddu    $a2, $s2, $zero
/* 10229C 802DF1AC 8E820000 */  lw        $v0, ($s4)
/* 1022A0 802DF1B0 50400011 */  beql      $v0, $zero, .L802DF1F8
/* 1022A4 802DF1B4 26730004 */   addiu    $s3, $s3, 4
/* 1022A8 802DF1B8 90A30004 */  lbu       $v1, 4($a1)
/* 1022AC 802DF1BC 90A20005 */  lbu       $v0, 5($a1)
/* 1022B0 802DF1C0 00620018 */  mult      $v1, $v0
/* 1022B4 802DF1C4 8CA40000 */  lw        $a0, ($a1)
/* 1022B8 802DF1C8 0000C012 */  mflo      $t8
/* 1022BC 802DF1CC 00188043 */  sra       $s0, $t8, 1
/* 1022C0 802DF1D0 0250A821 */  addu      $s5, $s2, $s0
/* 1022C4 802DF1D4 12440005 */  beq       $s2, $a0, .L802DF1EC
/* 1022C8 802DF1D8 26100008 */   addiu    $s0, $s0, 8
/* 1022CC 802DF1DC ACB20000 */  sw        $s2, ($a1)
/* 1022D0 802DF1E0 0240282D */  daddu     $a1, $s2, $zero
/* 1022D4 802DF1E4 0C019194 */  jal       bcopy
/* 1022D8 802DF1E8 0200302D */   daddu    $a2, $s0, $zero
.L802DF1EC:
/* 1022DC 802DF1EC AE750000 */  sw        $s5, ($s3)
/* 1022E0 802DF1F0 02509021 */  addu      $s2, $s2, $s0
/* 1022E4 802DF1F4 26730004 */  addiu     $s3, $s3, 4
.L802DF1F8:
/* 1022E8 802DF1F8 26310001 */  addiu     $s1, $s1, 1
/* 1022EC 802DF1FC 2A220064 */  slti      $v0, $s1, 0x64
/* 1022F0 802DF200 1440FFE7 */  bnez      $v0, .L802DF1A0
/* 1022F4 802DF204 26940004 */   addiu    $s4, $s4, 4
/* 1022F8 802DF208 0240302D */  daddu     $a2, $s2, $zero
.L802DF20C:
/* 1022FC 802DF20C 00111080 */  sll       $v0, $s1, 2
/* 102300 802DF210 0000882D */  daddu     $s1, $zero, $zero
/* 102304 802DF214 27A40010 */  addiu     $a0, $sp, 0x10
/* 102308 802DF218 00821021 */  addu      $v0, $a0, $v0
/* 10230C 802DF21C 24030001 */  addiu     $v1, $zero, 1
/* 102310 802DF220 AC430000 */  sw        $v1, ($v0)
/* 102314 802DF224 8ED30000 */  lw        $s3, ($s6)
/* 102318 802DF228 2407FFFF */  addiu     $a3, $zero, -1
/* 10231C 802DF22C AEC60000 */  sw        $a2, ($s6)
.L802DF230:
/* 102320 802DF230 8E650000 */  lw        $a1, ($s3)
/* 102324 802DF234 8C820000 */  lw        $v0, ($a0)
/* 102328 802DF238 10400003 */  beqz      $v0, .L802DF248
/* 10232C 802DF23C 26730004 */   addiu    $s3, $s3, 4
/* 102330 802DF240 080B7C93 */  j         .L802DF24C
/* 102334 802DF244 ACC50000 */   sw       $a1, ($a2)
.L802DF248:
/* 102338 802DF248 ACD50000 */  sw        $s5, ($a2)
.L802DF24C:
/* 10233C 802DF24C 10A70005 */  beq       $a1, $a3, .L802DF264
/* 102340 802DF250 24C60004 */   addiu    $a2, $a2, 4
/* 102344 802DF254 26310001 */  addiu     $s1, $s1, 1
/* 102348 802DF258 2A220064 */  slti      $v0, $s1, 0x64
/* 10234C 802DF25C 1440FFF4 */  bnez      $v0, .L802DF230
/* 102350 802DF260 24840004 */   addiu    $a0, $a0, 4
.L802DF264:
/* 102354 802DF264 0000882D */  daddu     $s1, $zero, $zero
/* 102358 802DF268 8EC30004 */  lw        $v1, 4($s6)
/* 10235C 802DF26C 2404FFFF */  addiu     $a0, $zero, -1
/* 102360 802DF270 AEC60004 */  sw        $a2, 4($s6)
.L802DF274:
/* 102364 802DF274 8C650000 */  lw        $a1, ($v1)
/* 102368 802DF278 24630004 */  addiu     $v1, $v1, 4
/* 10236C 802DF27C ACC50000 */  sw        $a1, ($a2)
/* 102370 802DF280 10A40005 */  beq       $a1, $a0, .L802DF298
/* 102374 802DF284 24C60004 */   addiu    $a2, $a2, 4
/* 102378 802DF288 26310001 */  addiu     $s1, $s1, 1
/* 10237C 802DF28C 2A220064 */  slti      $v0, $s1, 0x64
/* 102380 802DF290 1440FFF8 */  bnez      $v0, .L802DF274
/* 102384 802DF294 00000000 */   nop
.L802DF298:
/* 102388 802DF298 3C048035 */  lui       $a0, %hi(gSpriteHeapPtr)
/* 10238C 802DF29C 2484F800 */  addiu     $a0, $a0, %lo(gSpriteHeapPtr)
/* 102390 802DF2A0 02C0282D */  daddu     $a1, $s6, $zero
/* 102394 802DF2A4 0C00A4B1 */  jal       _heap_realloc
/* 102398 802DF2A8 00C53023 */   subu     $a2, $a2, $a1
/* 10239C 802DF2AC 8FBF01C8 */  lw        $ra, 0x1c8($sp)
/* 1023A0 802DF2B0 8FB701C4 */  lw        $s7, 0x1c4($sp)
/* 1023A4 802DF2B4 8FB601C0 */  lw        $s6, 0x1c0($sp)
/* 1023A8 802DF2B8 8FB501BC */  lw        $s5, 0x1bc($sp)
/* 1023AC 802DF2BC 8FB401B8 */  lw        $s4, 0x1b8($sp)
/* 1023B0 802DF2C0 8FB301B4 */  lw        $s3, 0x1b4($sp)
/* 1023B4 802DF2C4 8FB201B0 */  lw        $s2, 0x1b0($sp)
/* 1023B8 802DF2C8 8FB101AC */  lw        $s1, 0x1ac($sp)
/* 1023BC 802DF2CC 8FB001A8 */  lw        $s0, 0x1a8($sp)
/* 1023C0 802DF2D0 03E00008 */  jr        $ra
/* 1023C4 802DF2D4 27BD01D0 */   addiu    $sp, $sp, 0x1d0
