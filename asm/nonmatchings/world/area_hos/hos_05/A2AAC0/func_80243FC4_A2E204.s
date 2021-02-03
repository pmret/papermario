.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243FC4_A2E204
/* A2E204 80243FC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2E208 80243FC8 0000202D */  daddu     $a0, $zero, $zero
/* A2E20C 80243FCC 3C058024 */  lui       $a1, %hi(func_80243CC0_A2DF00)
/* A2E210 80243FD0 24A53CC0 */  addiu     $a1, $a1, %lo(func_80243CC0_A2DF00)
/* A2E214 80243FD4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A2E218 80243FD8 0C048C8F */  jal       bind_dynamic_entity_7
/* A2E21C 80243FDC AFB00010 */   sw       $s0, 0x10($sp)
/* A2E220 80243FE0 3C040001 */  lui       $a0, 1
/* A2E224 80243FE4 3C108025 */  lui       $s0, %hi(D_8024AA20_A34C60)
/* A2E228 80243FE8 2610AA20 */  addiu     $s0, $s0, %lo(D_8024AA20_A34C60)
/* A2E22C 80243FEC 8E030000 */  lw        $v1, ($s0)
/* A2E230 80243FF0 3484D420 */  ori       $a0, $a0, 0xd420
/* A2E234 80243FF4 0C0475F9 */  jal       func_8011D7E4
/* A2E238 80243FF8 AC620000 */   sw       $v0, ($v1)
/* A2E23C 80243FFC 3407A710 */  ori       $a3, $zero, 0xa710
/* A2E240 80244000 00471821 */  addu      $v1, $v0, $a3
/* A2E244 80244004 0000202D */  daddu     $a0, $zero, $zero
/* A2E248 80244008 8E060000 */  lw        $a2, ($s0)
/* A2E24C 8024400C 0080282D */  daddu     $a1, $a0, $zero
/* A2E250 80244010 ACC30008 */  sw        $v1, 8($a2)
/* A2E254 80244014 24630200 */  addiu     $v1, $v1, 0x200
/* A2E258 80244018 ACC3000C */  sw        $v1, 0xc($a2)
/* A2E25C 8024401C 00671821 */  addu      $v1, $v1, $a3
/* A2E260 80244020 ACC30010 */  sw        $v1, 0x10($a2)
/* A2E264 80244024 24630200 */  addiu     $v1, $v1, 0x200
/* A2E268 80244028 ACC30018 */  sw        $v1, 0x18($a2)
/* A2E26C 8024402C 24634000 */  addiu     $v1, $v1, 0x4000
/* A2E270 80244030 ACC3001C */  sw        $v1, 0x1c($a2)
/* A2E274 80244034 24634000 */  addiu     $v1, $v1, 0x4000
/* A2E278 80244038 ACC20004 */  sw        $v0, 4($a2)
/* A2E27C 8024403C 240200F0 */  addiu     $v0, $zero, 0xf0
/* A2E280 80244040 A4C20046 */  sh        $v0, 0x46($a2)
/* A2E284 80244044 2402006F */  addiu     $v0, $zero, 0x6f
/* A2E288 80244048 A4C20048 */  sh        $v0, 0x48($a2)
/* A2E28C 8024404C 24020036 */  addiu     $v0, $zero, 0x36
/* A2E290 80244050 ACC30020 */  sw        $v1, 0x20($a2)
/* A2E294 80244054 A4C0003C */  sh        $zero, 0x3c($a2)
/* A2E298 80244058 A4C0003E */  sh        $zero, 0x3e($a2)
/* A2E29C 8024405C A4C00040 */  sh        $zero, 0x40($a2)
/* A2E2A0 80244060 A4C00042 */  sh        $zero, 0x42($a2)
/* A2E2A4 80244064 A4C00044 */  sh        $zero, 0x44($a2)
/* A2E2A8 80244068 0C090FB4 */  jal       func_80243ED0_A2E110
/* A2E2AC 8024406C A4C2004A */   sh       $v0, 0x4a($a2)
/* A2E2B0 80244070 24040001 */  addiu     $a0, $zero, 1
/* A2E2B4 80244074 0C090FB4 */  jal       func_80243ED0_A2E110
/* A2E2B8 80244078 0080282D */   daddu    $a1, $a0, $zero
/* A2E2BC 8024407C 3C030002 */  lui       $v1, 2
/* A2E2C0 80244080 3463A440 */  ori       $v1, $v1, 0xa440
/* A2E2C4 80244084 3C050022 */  lui       $a1, 0x22
/* A2E2C8 80244088 24A591B0 */  addiu     $a1, $a1, -0x6e50
/* A2E2CC 8024408C 00A32021 */  addu      $a0, $a1, $v1
/* A2E2D0 80244090 24A54000 */  addiu     $a1, $a1, 0x4000
/* A2E2D4 80244094 8E020000 */  lw        $v0, ($s0)
/* A2E2D8 80244098 00A32821 */  addu      $a1, $a1, $v1
/* A2E2DC 8024409C 8C460018 */  lw        $a2, 0x18($v0)
/* A2E2E0 802440A0 0C00A5CF */  jal       dma_copy
/* A2E2E4 802440A4 24A54200 */   addiu    $a1, $a1, 0x4200
/* A2E2E8 802440A8 8E040000 */  lw        $a0, ($s0)
/* A2E2EC 802440AC 240300FF */  addiu     $v1, $zero, 0xff
/* A2E2F0 802440B0 A4800058 */  sh        $zero, 0x58($a0)
/* A2E2F4 802440B4 A483005A */  sh        $v1, 0x5a($a0)
/* A2E2F8 802440B8 A480005C */  sh        $zero, 0x5c($a0)
/* A2E2FC 802440BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2E300 802440C0 8FB00010 */  lw        $s0, 0x10($sp)
/* A2E304 802440C4 24020002 */  addiu     $v0, $zero, 2
/* A2E308 802440C8 03E00008 */  jr        $ra
/* A2E30C 802440CC 27BD0018 */   addiu    $sp, $sp, 0x18
