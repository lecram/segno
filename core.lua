local core = {}

function core.level(x)
    return {out=x}
end

function core.set_sr(sr)
    core.sample_rate = sr
    core.hz  = 1/sr
    core.sec = sr
end

function core.get_sr()
    return core.sample_rate
end

function core.tick(seq, dur)
    for i = 1, dur do
        for j, v in ipairs(seq) do v() end
    end
end

function core.close(seq)
    for i, v in ipairs(seq) do
        if type(v.close) == "function" then
            v:close()
        end
    end
end

function core.run(graph, events)
    table.sort(events, function (e1, e2) return e1[1] < e2[1] end)
    local index = 1
    local ev_time, ev_func = unpack(events[index])
    local sample = 0
    while true do
        while sample < ev_time do
            for k, v in pairs(graph) do
                v()
            end
            sample = sample + 1
        end
        if ev_func == nil then
            break
        else
            ev_func(graph)
        end
        index = index + 1
        ev_time, ev_func = unpack(events[index])
    end
    for k, v in pairs(graph) do
        if type(v.close) == "function" then
            v:close()
        end
    end
    return samples
end

core.set_sr(48000)

return core
